/*
 * \brief  Secured Digital Host Controller
 * \author Stefan Kalkowski
 * \date   2019-02-19
 */

/*
 * Copyright (C) 2019 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

/* local includes */
#include <driver.h>
#include <drivers/defs/imx6.h>

using namespace Sd_card;
using namespace Genode;

Driver::Driver(Env &env)
:
	Driver_base(env.ram()),
	Attached_mmio(env, Imx6::SDHC_2_MMIO_BASE, Imx6::SDHC_2_MMIO_SIZE),
	_env(env), _irq(env, Imx6::SDHC_2_IRQ)
{
	log("SD card detected");
	log("capacity: ", card_info().capacity_mb(), " MiB");
}
