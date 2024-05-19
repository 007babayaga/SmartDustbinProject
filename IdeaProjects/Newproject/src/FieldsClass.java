public class FieldsClass {
    private String name;
    private int age;

    @java.lang.Override
    public String toString() {
        return "FieldsClass{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }

    public FieldsClass(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
