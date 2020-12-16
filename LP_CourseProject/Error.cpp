#include "Error.h"
namespace Error {
	ERROR errors[ERROR_MAX_ENTRY] = {
		ERROR_ENTRY(0,  "Íåäàïóø÷àëüíû êîä ïàìûëê³"),
		ERROR_ENTRY(1,  "Ñ³ñòıìíû çáîé"),
		ERROR_ENTRY(2,  "Íåìàã÷ûìà ğàñïàçíàöü ëåêñåìó"),
		ERROR_ENTRY(3,  "Íå àòğûìàëàñÿ ¢ñòàëÿâàöü òûï ³äıíòûô³êàòàğà"),
		ERROR_ENTRY(4,  "Íå àòğûìàëàñÿ ¢ñòàëÿâàöü òûï äàäçåíûõ ³äıíòûô³êàòàğà"),
		ERROR_ENTRY(5,  "Ïåğàïà¢íåííå òàáë³öû ëåêñåì"),
		ERROR_ENTRY(6,  "Ïåğàïà¢íåííå òàáë³öû ³äıíòûô³êàòàğà¢"),
		ERROR_ENTRY(7,  "Ïàìûëêà ¢êëàäçåíàñö³ ôóíêöûé"),
		ERROR_ENTRY(8,  "²äıíòûô³êàòàğ ôóíêöû³ íå çíîéäçåíû"),
		ERROR_ENTRY(9,  "Íå àòğûìàëàñÿ ïàáóäàâàöü òàáë³öó ëåêñåì"),
		ERROR_ENTRY(10, "Ë³òığàë òûïó 'öıëû' çàäàäåíû íÿïğàâ³ëüíà"),
		ERROR_ENTRY(11, "Ïåğàìåííàÿ ¢æî àá'ÿ¢ëåíà"),
		ERROR_ENTRY(12, "Íåàäïàâåäíàñöü òûïà¢"),
		ERROR_ENTRY(13, "Íåàäïàâåäíàñöü òûïà¢ ïàğàìåòğà¢"),
		ERROR_ENTRY(14, "Íåàäïàâåäíàñöü êîëüêàñö³ ïàğàìåòğà¢"),
		ERROR_ENTRY(15, "Òûï, ÿê³ âÿğòàåööà ïàâ³íåí àäïàâÿäàöü òûïó ôóíêöû³"),
		ERROR_ENTRY(16, "Íå çíîéäçåíà ãàëî¢íàÿ ôóíêöûÿ"),
		ERROR_ENTRY(17, "Ôóíêöûÿ ¢æî àá'ÿ¢ëåíà"),
		ERROR_ENTRY_NODEF(18),ERROR_ENTRY_NODEF(19),
		ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30),
		ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),
		ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Ïàğàìåòàğ -in ïàâ³íåí áûöü çàäàäçíåíû"),
		ERROR_ENTRY(101, "Äà¢æûíÿ ¢âàõîäíàãà ïàğàìåòğà âåëüì³ âÿë³êàÿ"),
		ERROR_ENTRY(102, "Ïàìûëêà ïğû àäêğûöö³ ôàéëó ç çûõîäíûì êîäàì(-in)"),
		ERROR_ENTRY(103, "Íåäàïóø÷àëüíû çíàê ó çûõîäíûì êîäçå (-in)"),
		ERROR_ENTRY(104, "Ïàìûëêà ïğû ñòâàğıíí³ ïğàòàêîëó (-log)"),
		ERROR_ENTRY(105, "Ïàìûëêà ïğû ñòâàğıíí³ âûõàäíîãà ôàéëó (-out)"),
		ERROR_ENTRY(106, "Ïàìûëêà ïğû àäêğûöö³ á³áë³ÿòıöû"),
		ERROR_ENTRY_NODEF(107),ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110,"Íÿïğàâ³ëüíàÿ ñòğóêòóğà ïğàãğàìû"),
		ERROR_ENTRY(111, "Ïàìûëêîâû àïåğàòàğ"),
		ERROR_ENTRY(112, "Ïàìûëêà ¢ âûğàçå"),
		ERROR_ENTRY(113, "Ïàìûëêà ¢ ïàğàìåòğàõ ôóíêöû³"),
		ERROR_ENTRY(114, "Ïàìûëêà ¢ ïàğàìåòğàõ âûêë³êàíàé ôóíêöû³"),
		ERROR_ENTRY_NODEF10(110),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160),
		ERROR_ENTRY_NODEF10(170),ERROR_ENTRY_NODEF10(180),ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY_NODEF100(600),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900),
	};
	ERROR geterror(int id) {
		ERROR err;
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			err = errors[id];
		}
		else {
			err = errors[0];
		}
		return err;
	}
	ERROR geterrorin(int id, int line = -1, int col = -1) {
		ERROR err;
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			err = errors[id];
			err.inext.col = col;
			err.inext.line = line;
		}
		else {
			err = errors[0];
		}
		return err;
	}
}