import com.healthmarketscience.jackcess.*;
import com.healthmarketscience.jackcess.crypt.CryptCodecProvider;
import java.nio.file.*;
import java.util.*;
import java.nio.charset.StandardCharsets;

/** Read-only export of the supplied Jet database. Never prints its credential. */
public class DatabaseRecover {
  static Map<String,Object> obj(Object... args) {
    Map<String,Object> m = new LinkedHashMap<>();
    for(int i=0;i<args.length;i+=2) m.put((String)args[i], args[i+1]);
    return m;
  }
  static String json(Object x) {
    if(x==null) return "null";
    if(x instanceof byte[]) return json(obj("$binary_base64", Base64.getEncoder().encodeToString((byte[])x)));
    if(x instanceof Number || x instanceof Boolean) return x.toString();
    if(x instanceof Map<?,?>) {
      List<String> a=new ArrayList<>();
      for(var e:((Map<?,?>)x).entrySet()) a.add(json(e.getKey().toString())+":"+json(e.getValue()));
      return "{"+String.join(",",a)+"}";
    }
    if(x instanceof Iterable<?>) {
      List<String> a=new ArrayList<>(); for(Object v:(Iterable<?>)x) a.add(json(v));
      return "["+String.join(",",a)+"]";
    }
    StringBuilder b=new StringBuilder("\"");
    for(char c:x.toString().toCharArray()) {
      switch(c) {
        case '"':b.append("\\\"");break; case '\\':b.append("\\\\");break;
        case '\n':b.append("\\n");break; case '\r':b.append("\\r");break;
        case '\t':b.append("\\t");break;
        default:if(c<32)b.append(String.format("\\u%04x",(int)c));else b.append(c);
      }
    }
    return b.append('"').toString();
  }
  public static void main(String[] args) throws Exception {
    Path source=Path.of(args[0]), note=Path.of(args[1]), out=Path.of(args[2]);
    String password=null;
    for(String line:Files.readAllLines(note,StandardCharsets.UTF_8))
      if(line.startsWith("密码")) password=line.replaceFirst("^密码[：:]\\s*", "").trim();
    if(password==null) throw new IllegalArgumentException("No credential found in the supplied note");
    Files.createDirectories(out.resolve("tables"));
    try(Database db=new DatabaseBuilder(source).setReadOnly(true).setCodecProvider(new CryptCodecProvider(password)).open()) {
      // Jet legacy passwords are header checks; Jackcess exposes them independently of page decoding.
      boolean passwordMatches=password.equals(db.getDatabasePassword());
      List<Object> tables=new ArrayList<>(), queries=new ArrayList<>(), relations=new ArrayList<>();
      for(String name:new TreeSet<>(db.getTableNames())) {
        Table t=db.getTable(name); List<Object> cols=new ArrayList<>(), indexes=new ArrayList<>(), rows=new ArrayList<>();
        for(Column c:t.getColumns()) cols.add(obj("name",c.getName(),"type",c.getType().name(),"length_bytes",c.getLength(),"length_units",c.getLengthInUnits(),"auto_number",c.isAutoNumber(),"precision",c.getPrecision(),"scale",c.getScale()));
        for(Index i:t.getIndexes()) {
          List<Object> ic=new ArrayList<>(); for(Index.Column c:i.getColumns()) ic.add(obj("name",c.getName(),"ascending",c.isAscending()));
          indexes.add(obj("name",i.getName(),"primary_key",i.isPrimaryKey(),"unique",i.isUnique(),"foreign_key",i.isForeignKey(),"columns",ic));
        }
        for(Row r:t) rows.add(new LinkedHashMap<>(r));
        String filename=String.format("%02d.json",tables.size());
        Files.writeString(out.resolve("tables").resolve(filename),json(rows)+"\n",StandardCharsets.UTF_8);
        tables.add(obj("name",name,"declared_rows",t.getRowCount(),"exported_rows",rows.size(),"columns",cols,"indexes",indexes,"data_file","tables/"+filename));
      }
      for(var q:db.getQueries()) queries.add(obj("name",q.getName(),"type",q.getType().name(),"sql",q.toSQLString()));
      for(var r:db.getRelationships()) {
        List<String> from=new ArrayList<>(),to=new ArrayList<>();
        for(var c:r.getFromColumns())from.add(c.getName());for(var c:r.getToColumns())to.add(c.getName());
        relations.add(obj("name",r.getName(),"from_table",r.getFromTable().getName(),"from_columns",from,"to_table",r.getToTable().getName(),"to_columns",to,"referential_integrity",r.hasReferentialIntegrity()));
      }
      Files.writeString(out.resolve("schema.json"),json(obj("format",db.getFileFormat().name(),"read_only",true,"supplied_password_matches_header",passwordMatches,"tables",tables,"queries",queries,"relationships",relations,"system_table_names",new TreeSet<>(db.getSystemTableNames())))+"\n");
      System.out.println("Recovered "+tables.size()+" tables; supplied credential matches header: "+passwordMatches);
    }
  }
}
