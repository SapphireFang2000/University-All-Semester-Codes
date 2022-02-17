package demoteam;

public class Liverpool implements WeakTeam{
    String name;
    int maxplayer,maxtrophy,replacement;

    String weakvoice(){
        return "Weakvoice";
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
    public int getReplacementPlayer() {
        return replacement;
    }

    @Override
    public void setReplacementPlayer(int replacementPlayer) {
        this.replacement=replacementPlayer;
    }
}
