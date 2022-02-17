package structuretest;

public class Structure 
{
    private String structureName;
    private double structureVolume;

    public Structure() 
    {
        
    }

    public Structure(String structureName, double structureVolume) 
    {
        this.structureName = structureName;
        this.structureVolume = structureVolume;
    }

    public String getStructureName() 
    {
        return structureName;
    }

    public void setStructureName(String structureName) 
    {
        this.structureName = structureName;
    }

    public double getStructureVolume() 
    {
        return structureVolume;
    }

    public void setStructureVolume(double structureVolume) 
    {
        this.structureVolume = structureVolume;
    }
}
