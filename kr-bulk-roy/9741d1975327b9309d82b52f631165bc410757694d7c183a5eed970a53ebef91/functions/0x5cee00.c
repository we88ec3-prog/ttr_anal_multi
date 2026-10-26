
void FUN_005cee00(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00926ebe;
  local_14 = ExceptionList;
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar3 = *(int *)(param_1 + 8);
    if (iVar3 != *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
      if (iVar3 == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
        ExceptionList = &local_14;
        puVar2 = (undefined4 *)FUN_00891268(0x14);
        if (puVar2 != (undefined4 *)0x0) {
          puVar2[1] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          *puVar2 = FoxUI::FXUIEvent::vftable;
          puVar2[3] = 0;
          puVar2[4] = 0xf4307;
          FUN_00404aa0();
          FUN_00750020();
          ExceptionList = local_14;
          return;
        }
      }
      else if (iVar3 == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
        ExceptionList = &local_14;
        puVar2 = (undefined4 *)FUN_00891268(0x14);
        if (puVar2 != (undefined4 *)0x0) {
          puVar2[1] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          *puVar2 = FoxUI::FXUIEvent::vftable;
          puVar2[3] = 0;
          puVar2[4] = 0xf430a;
          FUN_00404aa0();
          FUN_00750020();
          ExceptionList = local_14;
          return;
        }
      }
      else {
        if (iVar3 != *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
          if (iVar3 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
            ExceptionList = &local_14;
            puVar2 = (undefined4 *)FUN_00891268(0x14);
            if (puVar2 != (undefined4 *)0x0) {
              puVar2[1] = 0xffffffff;
              puVar2[2] = 0xffffffff;
              *puVar2 = FoxUI::FXUIEvent::vftable;
              puVar2[3] = 0;
              puVar2[4] = 0xf4314;
            }
            FUN_00404aa0();
            FUN_00750020();
            iVar3 = FUN_004adcd0();
            *(undefined1 *)(iVar3 + 0x19) = 0;
            ExceptionList = local_14;
            return;
          }
          if (iVar3 == *(int *)(*(int *)(in_ECX + 0x2e0) + 0x20)) {
            ExceptionList = &local_14;
            FUN_00444960(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
          }
          else {
            if ((iVar3 != *(int *)(*(int *)(in_ECX + 0x30c) + 0x20)) &&
               (iVar3 != *(int *)(*(int *)(in_ECX + 0x310) + 0x20))) {
              if (iVar3 == *(int *)(*(int *)(in_ECX + 0x334) + 0x20)) {
                return;
              }
              if (iVar3 == *(int *)(*(int *)(in_ECX + 0x338) + 0x20)) {
                ExceptionList = &local_14;
                puVar2 = (undefined4 *)FUN_00891268(0x14);
                if (puVar2 != (undefined4 *)0x0) {
                  puVar2[1] = 0xffffffff;
                  puVar2[2] = 0xffffffff;
                  *puVar2 = FoxUI::FXUIEvent::vftable;
                  puVar2[3] = 0;
                  puVar2[4] = 0xf42f7;
                  FUN_00404aa0();
                  FUN_00750020();
                  ExceptionList = local_14;
                  return;
                }
              }
              else if (iVar3 == *(int *)(*(int *)(in_ECX + 0x33c) + 0x20)) {
                ExceptionList = &local_14;
                puVar2 = (undefined4 *)FUN_00891268(0x14);
                if (puVar2 != (undefined4 *)0x0) {
                  puVar2[1] = 0xffffffff;
                  puVar2[2] = 0xffffffff;
                  *puVar2 = FoxUI::FXUIEvent::vftable;
                  puVar2[3] = 0;
                  puVar2[4] = 0xf42f8;
                  FUN_00404aa0();
                  FUN_00750020();
                  ExceptionList = local_14;
                  return;
                }
              }
              else if (iVar3 == *(int *)(*(int *)(in_ECX + 0x340) + 0x20)) {
                ExceptionList = &local_14;
                puVar2 = (undefined4 *)FUN_00891268(0x14);
                if (puVar2 != (undefined4 *)0x0) {
                  puVar2[1] = 0xffffffff;
                  puVar2[2] = 0xffffffff;
                  *puVar2 = FoxUI::FXUIEvent::vftable;
                  puVar2[3] = 0;
                  puVar2[4] = 0xf42f9;
                  FUN_00404aa0();
                  FUN_00750020();
                  ExceptionList = local_14;
                  return;
                }
              }
              else {
                if (iVar3 != *(int *)(*(int *)(in_ECX + 0x344) + 0x20)) {
                  return;
                }
                ExceptionList = &local_14;
                puVar2 = (undefined4 *)FUN_00891268(0x14);
                if (puVar2 != (undefined4 *)0x0) {
                  puVar2[1] = 0xffffffff;
                  puVar2[2] = 0xffffffff;
                  *puVar2 = FoxUI::FXUIEvent::vftable;
                  puVar2[3] = 0;
                  puVar2[4] = 0xf42fd;
                  FUN_00404aa0();
                  FUN_00750020();
                  ExceptionList = local_14;
                  return;
                }
              }
              goto LAB_005cf20d;
            }
            ExceptionList = &local_14;
            FUN_00444960(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
          }
          FUN_0041e560();
          ExceptionList = local_14;
          return;
        }
        ExceptionList = &local_14;
        puVar2 = (undefined4 *)FUN_00891268(0x14);
        if (puVar2 != (undefined4 *)0x0) {
          puVar2[1] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          *puVar2 = FoxUI::FXUIEvent::vftable;
          puVar2[3] = 0;
          puVar2[4] = 0xf42de;
          FUN_00404aa0();
          FUN_00750020();
          ExceptionList = local_14;
          return;
        }
      }
LAB_005cf20d:
      FUN_00404aa0();
      FUN_00750020();
      ExceptionList = local_14;
      return;
    }
    ExceptionList = &local_14;
    piVar1 = (int *)FUN_00891268(0x14);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      *piVar1 = (int)FoxUI::FXUIEvent::vftable;
      piVar1[1] = -1;
      piVar1[2] = -1;
      piVar1[3] = 0;
      piVar1[4] = 0xf42d8;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 0;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar1);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(1);
      ExceptionList = pvStack_18;
      return;
    }
  }
  ExceptionList = local_14;
  return;
}

