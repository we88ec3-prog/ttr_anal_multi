
void FUN_007f7930(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  int local_44;
  int local_40;
  undefined4 *local_3c;
  int *local_38;
  undefined1 local_34 [24];
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009321b8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  iVar2 = DAT_00fb76a8;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  local_38 = (int *)0x0;
  if (*(int *)(iVar2 + 0xec) != 0) {
    (**(code **)(**(int **)(iVar2 + 0xec) + 4))(*(int **)(iVar2 + 0xec));
    local_38 = *(int **)(iVar2 + 0xec);
  }
  puVar4 = (undefined4 *)(unaff_EDI + 0x7c);
  local_3c = puVar4;
  D3DXCreateTexture(local_38,*(undefined4 *)(unaff_EDI + 0x3c),*(undefined4 *)(unaff_EDI + 0x3c),0,
                    0xffffffff,0x15,1,puVar4);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 3;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  (**(code **)(*(int *)*puVar4 + 0x44))((int *)*puVar4,0,local_34);
  (**(code **)(*(int *)*puVar4 + 0x4c))((int *)*puVar4,0,&local_44,0,0);
  uVar1 = 0;
  if (local_18 != 0) {
    do {
      uVar3 = 0;
      if (local_1c != 0) {
        do {
          iVar2 = (local_44 * uVar1 >> 2) + uVar3;
          *(uint *)(local_40 + iVar2 * 4) =
               (uint)*(byte *)(*(int *)(unaff_EDI + 0x38) + iVar2) << 0x18 | 0xffffff;
          uVar3 = uVar3 + 1;
          puVar4 = local_3c;
        } while (uVar3 < local_1c);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < local_18);
  }
  (**(code **)(*(int *)*puVar4 + 0x50))((int *)*puVar4,0);
  (**(code **)(*local_38 + 8))(local_38);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

