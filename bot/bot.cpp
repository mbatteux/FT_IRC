#include "bot.hpp"

bot::bot() {}

bot::~bot() {}

std::string    bot::fillTab(std::map<int, std::string> funfact)
{
    funfact[0] = "La population de la Terre est d'environ 8 milliards de personnes, mais il y a environ 10 quintillions (10 000 000 000 000 000 000) de fourmis sur la planète";
    funfact[1] = "Connaissiez-vous la plus haute montagne de l'univers exploré? C'est l'Olympe Mons sur Mars qui est 2,5 fois plus élevé que la plus haute montagne de la Terre, c'est-à-dire le mont. EVEREST";
    funfact[2] = "Les scientifiques ont trouvé une planète mystérieuse dans l'espace entièrement constituée de diamants. Les scientifiques ont donné à cette étonnante planète le nom de 55 Cancri E";
    funfact[3] = "Il y a un homme enterré sur la Lune";
    funfact[4] = "Il y a plus d'arbres sur Terre que d'etoiles dans la Voie Lactee ";
    funfact[5] = "Il y a plus de kangourous en Australie que d'habitants au Chili. ";
    funfact[6] = "Comment fonctionne la maintenance du cerveau ? il s'auto-mange (La phagocytose)";
    funfact[7] = "Trois-cents types de fromages différents sont produits en France, ce qui en fait le pays qui en produit le plus au monde";
    funfact[8] = "Votre estomac est suffisamment acide pour dissoudre du métal";
    funfact[9] = "Votre corps produit de la chaleur équivalente à celle d'une ampoule électrique de 100 watts chaque jour";
    funfact[10] = "Vos yeux peuvent percevoir jusqu'à 10 millions de couleurs différentes.";
    funfact[11] = "La surface des alvéoles pulmonaires, les minuscules sacs d'air dans vos poumons, est d'environ la taille d'un terrain de football";
    funfact[12] = "Si on prend tous vos vaisseaux et qu'on les met bout a bout pour en faire une corde, celle-ci ferait le tour de la planete Terre";
    return (funfact[rand() % 24]);
}

std::map<int, std::string> bot::getFunfact()
{
    return funfact;
}

void bot::flush(const std::string &message)
{
	std::string normalized = message + "\n";
	send(getSock(), normalized.c_str(), normalized.size(), 0);
}

void bot::userInfo()
{
	flush("PASS oui");
	flush("NICK Babidi");
	flush("USER BobidiBot");
}

int bot::getSock()
{
    return _socket;
}

void    bot::setSock(int sock)
{
    _socket = sock;
}

bool    bot::getStop()
{
    return _stop;
}

void    bot::sigInt_hdl(int signo)
{
    if (signo == SIGINT)
    {
        _stop = true;
        std::cout << "\b\b  \b\b" << std::endl;
    }
}
