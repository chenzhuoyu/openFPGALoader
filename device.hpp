#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <iostream>

#include "ftdijtag.hpp"

/* GGM: TODO: program must have an optional
 * offset
 * and question: bitstream to load bitstream in SPI mode must
 * be hardcoded or provided by user?
 */
class Device {
	public:
		enum prog_mode {
			NONE_MODE = 0,
			SPI_MODE,
			MEM_MODE
		};
		Device(FtdiJtag *jtag, enum prog_mode, std::string filename);
		virtual void program();
		int  idCode();
		void reset();
	protected:
		FtdiJtag *_jtag;
		std::string _filename;
		enum prog_mode _mode;
};

#endif
