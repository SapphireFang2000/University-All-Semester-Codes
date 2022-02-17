package structuretest;

import java.util.*;

public class StructureTest 
{
    public static void main(String[] args) 
    {
        DevelopStructure devStruct = new DevelopStructure();
        Structure struct = new Structure();
        
        Scanner scanner = new Scanner(System.in);
        
        double radius, base, height, length;
        
        System.out.print("Input 1 Value: ");
        radius = scanner.nextDouble();
        struct = devStruct.produceStructure(radius);
        System.out.println(struct.getStructureName() + " Volume " + struct.getStructureVolume());
        
        System.out.print("Input 2 Value: ");
        radius = scanner.nextDouble();
        height = scanner.nextDouble();
        struct = devStruct.produceStructure(radius, height);
        System.out.println(struct.getStructureName() + " Volume " + struct.getStructureVolume());
        
        System.out.print("Input 3 Value: ");
        base = scanner.nextDouble();
        height = scanner.nextDouble();
        length = scanner.nextDouble();
        struct = devStruct.produceStructure(base, height, length);
        System.out.println(struct.getStructureName() + " Volume " + struct.getStructureVolume());
    }
    
}
