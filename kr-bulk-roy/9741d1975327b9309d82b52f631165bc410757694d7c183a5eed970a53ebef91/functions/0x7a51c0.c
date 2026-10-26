
void FUN_007a51c0(undefined4 *param_1)

{
  uint uVar1;
  undefined4 ***pppuVar2;
  char cVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 **local_38;
  undefined4 *local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_009392c6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = IS3D::CDoll::vftable;
  param_1[1] = IS3D::CDoll::vftable;
  param_1[2] = IS3D::CDoll::vftable;
  param_1[3] = IS3D::CDoll::vftable;
  local_8 = 0xd;
  if (param_1[9] == 1) {
    local_38 = (undefined4 **)0x7a521e;
    iVar4 = FUN_00891268();
    local_8._0_1_ = 0xe;
    if (iVar4 != 0) {
      local_38 = (undefined4 **)0x7a5234;
      FUN_007a5680();
    }
    local_38 = &local_1c;
    local_8._0_1_ = 0xd;
    local_1c = (undefined4 *)0x0;
    local_18 = (int *)0x0;
    FUN_007aa780();
    puVar6 = local_1c;
    local_8 = CONCAT31(local_8._1_3_,0xf);
    *local_1c = param_1[6];
    local_38 = (undefined4 **)0x7a5264;
    FUN_007a5730();
    puVar6[1] = param_1[7];
    if (puVar6 + 10 != param_1 + 0x1b) {
      local_38 = *(undefined4 ***)puVar6[0xb];
      FUN_006d7120();
      local_38 = (undefined4 **)0x7a5290;
      FUN_007aa150();
      puVar6 = local_1c;
    }
    param_1[7] = 0;
    FUN_00597b70();
    if ((int *)param_1[0x28] != (int *)0x0) {
      piVar7 = (int *)(*(int *)param_1[0x28] + 0x2c);
      *piVar7 = *piVar7 + -1;
      local_38 = (undefined4 **)0x7a52b9;
      FUN_0089120c();
      param_1[0x28] = 0;
    }
    piVar7 = local_18;
    local_14 = (undefined1 *)&local_38;
    local_38 = (undefined4 **)0x0;
    pppuVar2 = &local_38;
    if ((local_18 != (int *)0x0) &&
       (cVar3 = FUN_0047c250(), pppuVar2 = (undefined4 ***)local_14, cVar3 != '\0')) {
      FUN_007a31c0(puVar6,piVar7);
      pppuVar2 = (undefined4 ***)local_14;
    }
    local_14 = (undefined1 *)pppuVar2;
    uVar1 = local_8 >> 8;
    if ((DAT_00fc0f60 & 1) == 0) {
      DAT_00fc0f60 = DAT_00fc0f60 | 1;
      local_8._0_1_ = 0x11;
      FUN_0079cf40();
      _atexit((_func_4879 *)&LAB_00bcdb80);
      uVar1 = (uint)local_8._1_3_;
    }
    local_8._1_3_ = (uint3)uVar1;
    local_8._0_1_ = 0xf;
    FUN_0079de00();
    local_8 = CONCAT31(local_8._1_3_,0xd);
    if (piVar7 != (int *)0x0) {
      LOCK();
      iVar4 = piVar7[1] + -1;
      piVar7[1] = iVar4;
      UNLOCK();
      if (iVar4 == 0) {
        (**(code **)*piVar7)();
        LOCK();
        iVar4 = piVar7[2] + -1;
        piVar7[2] = iVar4;
        UNLOCK();
        if (iVar4 == 0) {
          (**(code **)(*piVar7 + 4))();
        }
      }
    }
  }
  FUN_007be5f0();
  if ((int *)param_1[0x48] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x48] + 0x10))();
    (**(code **)(*(int *)param_1[0x48] + 8))();
    param_1[0x48] = 0;
  }
  piVar7 = *(int **)param_1[0x43];
  if (piVar7 != (int *)param_1[0x43]) {
    do {
      piVar5 = (int *)piVar7[2];
      if (piVar5 != (int *)0x0) {
        *(int *)(*piVar5 + 0x60) = *(int *)(*piVar5 + 0x60) + -1;
        if ((piVar5[0x1d] == 0) || (piVar5[0x1e] == 0)) {
          if (0 < piVar5[0x1d]) {
            local_38 = (undefined4 **)0x7a53f9;
            FUN_007be0f0();
          }
        }
        else {
          local_14 = (undefined1 *)*piVar5;
          local_18 = piVar5;
          if (0 < *(int *)(local_14 + 0x44)) {
            lpCriticalSection = (LPCRITICAL_SECTION)(local_14 + 100);
            local_38 = (undefined4 **)0x7a53d4;
            EnterCriticalSection(lpCriticalSection);
            FUN_007bb350();
            local_38 = (undefined4 **)0x7a53ec;
            LeaveCriticalSection(lpCriticalSection);
            goto LAB_007a5407;
          }
        }
        FUN_007bd850();
        local_38 = (undefined4 **)0x7a5404;
        FUN_0089120c();
      }
LAB_007a5407:
      piVar5 = (int *)piVar7[3];
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x10))();
        (**(code **)(*piVar5 + 8))();
      }
      piVar5 = (int *)*piVar7;
      if (piVar7 != (int *)param_1[0x43]) {
        *(int **)piVar7[1] = piVar5;
        *(int *)(*piVar7 + 4) = piVar7[1];
        local_38 = (undefined4 **)0x7a543d;
        FUN_0089120c();
        param_1[0x44] = param_1[0x44] + -1;
      }
      piVar7 = piVar5;
    } while (piVar5 != (int *)param_1[0x43]);
  }
  piVar7 = (int *)param_1[0x43];
  piVar5 = (int *)*piVar7;
  *piVar7 = (int)piVar7;
  *(undefined4 *)(param_1[0x43] + 4) = param_1[0x43];
  param_1[0x44] = 0;
  if (piVar5 != (int *)param_1[0x43]) {
    do {
      piVar5 = (int *)*piVar5;
      local_38 = (undefined4 **)0x7a5488;
      FUN_0089120c();
    } while (piVar5 != (int *)param_1[0x43]);
  }
  if (param_1[0x57] != 0) {
    FUN_007d7300();
    local_38 = (undefined4 **)0x7a54aa;
    FUN_0089120c();
    param_1[0x57] = 0;
  }
  FUN_00597b70();
  if (param_1[0x58] != 0) {
    local_38 = (undefined4 **)0x7a54da;
    FUN_007aa8b0();
    local_38 = (undefined4 **)param_1[0x58];
    FUN_0089120c();
  }
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  if (param_1[0x53] != 0) {
    local_38 = (undefined4 **)0x7a550b;
    FUN_0089120c();
  }
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  piVar7 = (int *)param_1[0x43];
  piVar5 = (int *)*piVar7;
  *piVar7 = (int)piVar7;
  *(undefined4 *)(param_1[0x43] + 4) = param_1[0x43];
  param_1[0x44] = 0;
  if (piVar5 != (int *)param_1[0x43]) {
    do {
      piVar5 = (int *)*piVar5;
      local_38 = (undefined4 **)0x7a5549;
      FUN_0089120c();
    } while (piVar5 != (int *)param_1[0x43]);
  }
  local_38 = (undefined4 **)0x7a5562;
  FUN_0089120c();
  if (param_1[0x24] != 0) {
    local_38 = (undefined4 **)0x7a5575;
    FUN_0089120c();
  }
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  local_8._0_1_ = 0x12;
  local_38 = *(undefined4 ***)param_1[0x20];
  FUN_005540c0();
  local_38 = (undefined4 **)0x7a55ae;
  FUN_0089120c();
  local_8._0_1_ = 0x13;
  local_38 = *(undefined4 ***)param_1[0x1c];
  FUN_006d7120();
  local_38 = (undefined4 **)0x7a55d5;
  FUN_0089120c();
  local_8._0_1_ = 0x14;
  local_38 = *(undefined4 ***)param_1[0x18];
  FUN_006d7120();
  local_38 = (undefined4 **)0x7a55fc;
  FUN_0089120c();
  local_8._0_1_ = 0x15;
  local_38 = *(undefined4 ***)param_1[0x14];
  FUN_004ca160();
  local_38 = (undefined4 **)0x7a5623;
  FUN_0089120c();
  local_8._0_1_ = 4;
  local_38 = (undefined4 **)0x7a5633;
  FUN_007a5120();
  local_8 = CONCAT31(local_8._1_3_,3);
  piVar7 = (int *)param_1[5];
  if (piVar7 != (int *)0x0) {
    LOCK();
    iVar4 = piVar7[2] + -1;
    piVar7[2] = iVar4;
    UNLOCK();
    if (iVar4 == 0) {
      (**(code **)(*piVar7 + 4))();
    }
  }
  param_1[3] = IS3D::CShadowCaster::vftable;
  param_1[2] = IDXManagedObject::vftable;
  param_1[1] = IS3D::IObject::vftable;
  *param_1 = IS3D::IRenderable::vftable;
  ExceptionList = local_10;
  return;
}

