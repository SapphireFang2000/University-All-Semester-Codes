package demoteam;

public class Main {

    public static void main(String[] args) {
        Liverpool lp = new Liverpool();
        ManchesterUnited mu= new ManchesterUnited();
        Fifa ff = new Fifa();

        mu.setName("Manchester United");
        mu.setMaxTrophy(46);
        mu.setMaxPlayers(33);
        mu.setNumTournaments(4);

        System.out.println("Team is : "+mu.getName());
        System.out.println("Max trophy : "+mu.getMaxTrophy());
        System.out.println("Total Tournaments: "+mu.getNumTournaments());
        System.out.println("Total Players: "+mu.getMaxPlayers());
        System.out.println("Has "+mu.Fanvoice());
        System.out.println();


        lp.setName("Liverpool");
        lp.setMaxPlayers(31);
        lp.setMaxTrophy(44);
        lp.setReplacementPlayer(12);

        System.out.println("Team is : "+lp.getName());
        System.out.println("Max trophy : "+lp.getMaxTrophy());
        System.out.println("total Replacements: "+lp.getReplacementPlayer());
        System.out.println("Total Players: "+lp.getMaxPlayers());
        System.out.println("Has "+lp.weakvoice());
        System.out.println();


        ff.setName("FIFA");
        ff.setMaxTrophy(120);
        ff.setMaxPlayers(100);
        ff.setNumTournaments(12);
        ff.Type();
        ff.worldSound();
        System.out.println("Team is : "+ff.getName());
        System.out.println("Max trophy: "+ff.getMaxTrophy());
        System.out.println("Total Tournaments: "+ff.getNumTournaments());
        System.out.println("Total players: "+ff.getMaxPlayers());
    }
}
