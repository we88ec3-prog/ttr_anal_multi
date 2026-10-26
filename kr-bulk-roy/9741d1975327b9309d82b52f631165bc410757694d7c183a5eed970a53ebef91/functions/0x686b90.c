
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00686b90(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  uint extraout_ECX;
  int *piVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  uVar2 = param_1[4];
  if (uVar2 < 0xf437b) {
    if (uVar2 == 0xf437a) {
      iVar3 = (**(code **)(*param_1 + 4))();
      if (iVar3 != 0x105bd) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        param_1 = (int *)0x0;
      }
      if (param_1[5] == 0x6a7) {
        *(undefined1 *)((int)in_ECX + 0x172) = 1;
      }
      else if (param_1[5] == 0x6a8) {
        *(undefined1 *)((int)in_ECX + 0x172) = 0;
      }
      FUN_00688bf0(in_ECX[0x5e]);
      return;
    }
    if (uVar2 == 0x578) {
      iVar3 = param_1[2];
      if (iVar3 == *(int *)(in_ECX[0x4e] + 0x20)) {
        FUN_006872a0();
        return;
      }
      if (iVar3 != *(int *)(in_ECX[0x4f] + 0x20)) {
        if (iVar3 == *(int *)(in_ECX[0x4b] + 0x20)) {
          FUN_00687930();
          return;
        }
        if (iVar3 == *(int *)(in_ECX[0x54] + 0x20)) {
          iVar3 = in_ECX[0x53];
          iVar1 = FUN_0075cdd0();
          if (iVar1 == 0) {
            FUN_0046aa50();
          }
          else {
            FUN_0075cdd0();
          }
        }
        else {
          if (iVar3 != *(int *)(in_ECX[0x55] + 0x20)) {
            if (iVar3 == *(int *)(in_ECX[0x57] + 0x20)) {
              iVar3 = in_ECX[0x56];
              iVar1 = FUN_0075cdd0();
              if (iVar1 == 0) {
                FUN_0046aa50();
              }
              else {
                FUN_0075cdd0();
              }
            }
            else {
              if (iVar3 != *(int *)(in_ECX[0x58] + 0x20)) {
                return;
              }
              iVar3 = in_ECX[0x56];
              FUN_0046aa50();
              uVar2 = FUN_0075cdd0();
              if (uVar2 < extraout_ECX) {
                FUN_0075cdd0();
              }
            }
            FUN_0075cd30(iVar3);
            FUN_0075cdb0();
            FUN_00757710();
            (**(code **)(*(int *)in_ECX[0x56] + 200))();
            FUN_00687f30(in_ECX,in_ECX + 0x3f);
            return;
          }
          iVar3 = in_ECX[0x53];
          FUN_0046aa50();
          uVar6 = FUN_0075cdd0();
          if ((uint)uVar6 < (uint)((ulonglong)uVar6 >> 0x20)) {
            FUN_0075cdd0();
          }
        }
        FUN_0075cd30(iVar3);
        FUN_0075cdb0();
        FUN_00757710();
        (**(code **)(*(int *)in_ECX[0x53] + 200))();
        FUN_00687f30(in_ECX,in_ECX + 0x3f);
        return;
      }
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (uVar2 != 0x641) {
      return;
    }
    if (param_1[2] == *(int *)(in_ECX[0x53] + 0x20)) {
      FUN_00687f30(in_ECX,in_ECX + 0x3f);
    }
    if (param_1[2] != *(int *)(in_ECX[0x56] + 0x20)) {
      return;
    }
    FUN_00687f30(in_ECX,in_ECX + 0x3f);
    return;
  }
  if (uVar2 != 0xf43a9) {
    if (uVar2 != 0xf43aa) {
      return;
    }
    FUN_00687300();
    return;
  }
  if (*(int *)(in_ECX[0x53] + 0x24c) == 0) {
LAB_00686e9c:
    iVar3 = -1;
  }
  else {
    iVar3 = *(int *)(*(int *)(in_ECX[0x53] + 0x24c) + 0xcc);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xdc);
    }
    if (iVar3 == 0) goto LAB_00686e9c;
    iVar3 = *(int *)(iVar3 + 0x20);
  }
  if (iVar3 == 0) {
    piVar4 = (int *)0x0;
  }
  else if (iVar3 == 1) {
    piVar4 = (int *)0x2;
  }
  else {
    piVar4 = in_ECX;
    if (iVar3 == 2) {
      piVar4 = (int *)0x3;
    }
  }
  if (*(int *)(in_ECX[0x56] + 0x24c) != 0) {
    iVar3 = *(int *)(*(int *)(in_ECX[0x56] + 0x24c) + 0xcc);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xdc);
    }
    if (iVar3 != 0) {
      uVar5 = *(undefined4 *)(iVar3 + 0x20);
      goto LAB_00686eee;
    }
  }
  uVar5 = 0xffffffff;
LAB_00686eee:
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  FUN_004a3bf0(in_ECX[0x3d],in_ECX[0x3e],piVar4,uVar5,*(undefined1 *)((int)in_ECX + 0x172));
  return;
}

