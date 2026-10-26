
void FUN_007998a0(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piStack_5c;
  undefined1 uStack_55;
  int *local_54;
  undefined4 uStack_50;
  int *piStack_4c;
  undefined **ppuStack_48;
  int *piStack_44;
  int *piStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_24;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00932642;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&piStack_5c;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  local_54 = param_1;
  FUN_0079ac50(param_1);
  iVar3 = param_1[3];
  if (*(int *)(iVar3 + 0xdc) - *(int *)(iVar3 + 0xd8) >> 2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = **(int **)(iVar3 + 0xd8);
  }
  if (((*(int **)(iVar3 + 0x74) != (int *)0x0) &&
      (iVar2 = (**(code **)(**(int **)(iVar3 + 0x74) + 0x24))(uVar1), iVar2 != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar3 + 0x74) + 0x38))(), 0 < iVar2)) {
    (**(code **)(**(int **)(iVar3 + 0x74) + 0x28))(0);
  }
  iVar3 = FUN_00843ef0();
  uVar1 = DAT_00fe1df8 & 1;
  *(undefined4 *)(iVar3 + 0x24) = 0;
  if (uVar1 == 0) {
    DAT_00fe1df8 = DAT_00fe1df8 | 1;
    uStack_c = 0;
    FUN_00716be0();
    _atexit((_func_4879 *)&LAB_00bcf1a0);
    uStack_c = 0xffffffff;
  }
  piVar4 = (int *)FUN_00716830();
  piStack_4c = piVar4;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x11));
  piVar6 = *(int **)piVar4[1];
  if (piVar6 != (int *)piVar4[1]) {
    do {
      uStack_3c = 0;
      FUN_0079c590();
      uStack_c = 1;
      piStack_44 = (int *)FUN_0079a5f0(param_1);
      piStack_40 = &uStack_50;
      ppuStack_48 = `long___cdecl_Graphics::LoadTextureFromFile(IDirect3DDevice9*,char_const*,IDirect3DTexture9**)'
                    ::__l2::CreateTextureFromFileBox::vftable;
      iVar3 = FUN_00737d40();
      uStack_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      if (iVar3 == 0) {
        puVar5 = (undefined4 *)(piVar6[9] + 0x1c);
        if (0xf < *(uint *)(piVar6[9] + 0x30)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        (**(code **)(*(int *)*local_54 + 0x50))(puVar5,uStack_50,&uStack_3c);
        (**(code **)(*piStack_5c + 8))(piStack_5c);
      }
      piVar6 = (int *)*piVar6;
      param_1 = local_54;
    } while (piVar6 != (int *)piStack_4c[1]);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x11));
  if ((DAT_00fe321c & 1) == 0) {
    DAT_00fe321c = DAT_00fe321c | 1;
    uStack_c = 2;
    FUN_007d0fb0(&uStack_55);
    _atexit((_func_4879 *)&LAB_00bd09c0);
    uStack_c = 0xffffffff;
  }
  piVar6 = (int *)FUN_007d0920(0);
  param_1[4] = (int)piVar6;
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 0x58))(*param_1);
  }
  if ((DAT_00fe321c & 1) == 0) {
    DAT_00fe321c = DAT_00fe321c | 1;
    uStack_c = 3;
    FUN_007d0fb0(&uStack_55);
    _atexit((_func_4879 *)&LAB_00bd09c0);
    uStack_c = 0xffffffff;
  }
  piVar6 = (int *)FUN_007d0920(0);
  param_1[5] = (int)piVar6;
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 0x58))(*param_1);
  }
  iVar3 = *param_1;
  piVar6 = piStack_4c;
  if (*(int *)(iVar3 + 0xec) != 0) {
    (**(code **)(**(int **)(iVar3 + 0xec) + 4))(*(int **)(iVar3 + 0xec));
    piVar6 = *(int **)(iVar3 + 0xec);
  }
  piStack_40 = param_1 + 0x23;
  ppuStack_48 = `long___cdecl_Graphics::LoadTextureFromFile(IDirect3DDevice9*,char_const*,IDirect3DTexture9**)'
                ::__l2::CreateTextureFromFileBox::vftable;
  piStack_44 = piVar6;
  FUN_00737d40();
  (**(code **)(*(int *)param_1[0x28] + 4))();
  (**(code **)(*piVar6 + 8))(piVar6);
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffffa0);
  return;
}

