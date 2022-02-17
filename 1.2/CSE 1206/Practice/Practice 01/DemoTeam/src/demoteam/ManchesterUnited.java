package demoteam;

public class ManchesterUnited implements StrongTeam{
    String name;
    int maxplayer,maxtrophy,numtournament;

    String Fanvoice(){
        return "Fanvoice";
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
    public void setMaxTrophy(int maxtrophy) {
        this.maxtrophy=maxtrophy;
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
