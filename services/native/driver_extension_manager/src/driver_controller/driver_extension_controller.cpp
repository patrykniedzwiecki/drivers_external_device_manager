/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ability_manager_client.h"
#include "hilog_wrapper.h"
#include "driver_extension_controller.h"
using namespace OHOS;
using namespace OHOS::ExternalDeviceManager;
static const uint32_t UEC_OK = 0

int DriverExtensionController::StartDriverExtension(
    std::string bundleName,
    std::string abilityName)
{
    EDM_LOGI("Begin to start DriverExtension, bundle:%{public}s, ability:%{public}s", \
        bundleName.c_str(), abilityName.c_str());
    auto abmc = AAFwk::AbilityManagerClient::GetInstance();
    if (abmc == nullptr) {
        EDM_LOGE("Get AMC Instance failed");
        return -1;
    }
    AAFwk::Want want;
    want.SetElementName(bundleName, abilityName);

    auto ret = abmc->StartExtensionAbility(want, nullptr);
    if (ret != UEC_OK) {
        EDM_LOGE("StartExtensionAbility failed %{public}d", ret);
        return ret;
    }
    EDM_LOGI("StartExtensionAbility success");
    return 0;
}


int DriverExtensionController::StopDriverExtension(
    std::string bundleName,
    std::string abilityName)
{
    EDM_LOGI("Begin to stop DriverExtension, bundle:%{public}s, ability:%{public}s", \
        bundleName.c_str(), abilityName.c_str());
    auto abmc = AAFwk::AbilityManagerClient::GetInstance();
    if (abmc == nullptr) {
        EDM_LOGE("Get AMC Instance failed");
        return -1;
    }
    AAFwk::Want want;
    want.SetElementName(bundleName, abilityName);
    auto ret = abmc->StopExtensionAbility(want, nullptr);
    if (ret != UEC_OK) {
        EDM_LOGE("StopExtensionAbility failed %{public}d", ret);
        return ret;
    }
    EDM_LOGI("StopExtensionAbility success");
    return 0;
}