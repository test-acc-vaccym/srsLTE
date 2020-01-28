/*
 * Copyright 2013-2019 Software Radio Systems Limited
 *
 * This file is part of srsLTE.
 *
 * srsLTE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsLTE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#ifndef SRSLTE_SCHEDULER_TEST_COMMON_H
#define SRSLTE_SCHEDULER_TEST_COMMON_H

#include "srsenb/hdr/stack/mac/scheduler.h"

namespace srsenb {

// helpers
int extract_dl_prbmask(const srslte_cell_t&               cell,
                       const srslte_dci_dl_t&             dci,
                       srslte::bounded_bitset<100, true>* alloc_mask);

class output_sched_tester
{
public:
  explicit output_sched_tester(const sched_params_t& params_) : params(params_) {}

  /* Check for collisions between RB allocations in the PUSCH and PUCCH */
  int test_ul_rb_collisions(const tti_params_t&                    tti_params,
                            const sched_interface::ul_sched_res_t& ul_result,
                            prbmask_t&                             ul_allocs) const;

  /* Check for collision between RB allocations in the PDSCH */
  int test_dl_rb_collisions(const tti_params_t&                    tti_params,
                            const sched_interface::dl_sched_res_t& dl_result,
                            rbgmask_t&                             dl_mask) const;

  /* Check if SIBs are scheduled within their window */
  int test_sib_scheduling(const tti_params_t& tti_params, const sched_interface::dl_sched_res_t& dl_result) const;

private:
  const sched_params_t& params;
};

} // namespace srsenb

#endif // SRSLTE_SCHEDULER_TEST_COMMON_H