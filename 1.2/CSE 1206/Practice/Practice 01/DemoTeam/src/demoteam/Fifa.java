package demoteam;

public class Fifa extends Combined implements StrongTeam{
    String name;
    int maxplayer,maxtrophy,numtournament;
    @Override
    void worldSound(){
        System.out.println("Importancy");
    }
    @Override
    public String getName() {
        return name;
    }

    @Override
    public void setName(String name) {
        this.name= name;
    }

    @Override
    public int getMaxPlayers() {
        return maxplayer;
    }

    @Override
    public void setMaxPlayers(int maxPlayers) {
        this.maxplayer=maxPlayers;
    }

    @Override
    public int getMaxTrophy() {
        return maxtrophy;
    }

    @Override
    public void setMaxTrophy(int maxTrophy) {
        this.maxtrophy=maxTrophy;
    }
    @Override
    public int getNumTournaments() {
        return numtournament;
    }

    @Override
    public void setNumTournaments(int numtournaments) {
        this.numtournament=numtournaments;
    }


}
