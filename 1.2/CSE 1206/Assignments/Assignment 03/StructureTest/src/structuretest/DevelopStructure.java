package structuretest;

public class DevelopStructure 
{
    //Using Constructor Method
    Structure produceStructure(double radius)
    {
        double structureVolume = ((double)4/3) * Math.PI * Math.pow(radius, 3);
        String structureName = "Sphere";
        
        Structure structObj1 = new Structure(structureName, structureVolume);
        
        return structObj1;
    }
    
    Structure structObj2 = new Structure();
    
    //Using Getter and Setter Method
    Structure produceStructure(double radius, double height)
    {
        double structureVolume = ((double)1/3) * Math.PI * Math.pow(radius, 2) * height;
        String structureName = "Cone";
        
        structObj2.setStructureVolume(structureVolume);
        structObj2.setStructureName(structureName);
        
        return structObj2;
    }
    
    Structure produceStructure(double base, double height, double length)
    {
        double structureVolume = ((double)1/2) * (base * height) * length;
        String structureName = "Triangular Prism";
        
        structObj2.setStructureVolume(structureVolume);
        structObj2.setStructureName(structureName);
        
        return structObj2;
    }
}
