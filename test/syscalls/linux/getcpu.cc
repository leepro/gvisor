// Copyright 2018 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <sched.h>

#include "gtest/gtest.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"
#include "test/util/test_util.h"

namespace gvisor {
namespace testing {

namespace {

TEST(GetcpuTest, IsValidCpuStress) {
  const int num_cpus = NumCPUs();
  absl::Time deadline = absl::Now() + absl::Seconds(10);
  while (absl::Now() < deadline) {
    int cpu;
    ASSERT_THAT(cpu = sched_getcpu(), SyscallSucceeds());
    ASSERT_LT(cpu, num_cpus);
  }
}

}  // namespace

}  // namespace testing
}  // namespace gvisor
