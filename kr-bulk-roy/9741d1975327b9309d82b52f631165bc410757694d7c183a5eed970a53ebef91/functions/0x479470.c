
void FUN_00479470(undefined2 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint local_38;
  int *local_34;
  undefined4 local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_009410cf;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  local_8 = 0;
  iVar2 = FUN_00404ba0(local_14);
  iVar2 = *(int *)(iVar2 + 0x6928);
  if ((DAT_00fbace4 & 1) == 0) {
    DAT_00fbace4 = DAT_00fbace4 | 1;
    local_8 = 1;
    FUN_00825080();
    _atexit((_func_4879 *)&LAB_00bcd6d0);
    local_8 = local_8 & 0xffffff00;
  }
  iVar1 = (uint)param_2 * 4;
  local_34 = (int *)(uint)*(byte *)(iVar1 + 2 + DAT_00fbacf0);
  FUN_004dae30(&local_34);
  iVar3 = local_38 + 0x10;
  if (local_38 == *(uint *)(iVar2 + 4)) {
    iVar3 = iVar2 + 0x30;
  }
  if ((iVar3 != 0) && (*(char *)(iVar1 + 3 + DAT_00fbacf0) != '\0')) {
    FUN_004041f0(iVar3 + 0x1c,0,0xffffffff);
  }
  local_38 = *(uint *)(iVar1 + DAT_00fbacf0) >> 0x10 & 0xff;
  FUN_004daea0(&local_38);
  if (((local_34 != *(int **)(iVar2 + 0x24)) && (FUN_00515a30(), local_38 != local_34[5])) &&
     (local_34 = (int *)(local_38 + 0x10), local_34 != (int *)0x0)) {
    FUN_00404300(&DAT_00bfb894,1);
    FUN_00404300(L"<#FFFF00>",9);
    iVar2 = *local_34;
    iVar3 = local_34[1] - iVar2 >> 3;
    uVar5 = 0;
    if (iVar3 != 0) {
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      do {
        local_38 = *(uint *)(iVar2 + uVar5 * 8);
        FUN_005740f0(&local_38);
        uVar4 = FUN_006ca4f0(local_30);
        local_8 = 2;
        FUN_004041f0(uVar4,0,0xffffffff);
        local_8 = local_8 & 0xffffff00;
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        if (uVar5 != (local_34[1] - *local_34 >> 3) - 1U) {
          FUN_00404300(&DAT_00c02b94,2);
        }
        iVar2 = *local_34;
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)(local_34[1] - iVar2 >> 3));
    }
    FUN_00404300(L"<br>",4);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

