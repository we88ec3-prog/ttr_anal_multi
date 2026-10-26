
void FUN_007b5c90(int param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  char *in_ECX;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ec08;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar4 = in_ECX;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  local_14 = uVar3;
  FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
  local_54 = param_1 + 0x9c;
  local_8 = 0;
  local_58 = FUN_007b6f30(local_30);
  if ((local_58 == *(int *)(param_1 + 0xa0)) || (cVar2 = FUN_0049ae30(uVar3), cVar2 != '\0')) {
    local_50 = *(int *)(param_1 + 0xa0);
    piVar5 = &local_50;
  }
  else {
    piVar5 = &local_58;
  }
  iVar1 = *piVar5;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  uVar3 = local_30[0] >> 8;
  local_30[0] = uVar3 << 8;
  if ((iVar1 != *(int *)(param_1 + 0xa0)) &&
     (piVar5 = (int *)(*(int *)(iVar1 + 0x28) + 0x20), *piVar5 = *piVar5 + -1,
     *(int *)(*(int *)(iVar1 + 0x28) + 0x20) == 0)) {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = uVar3 << 8;
    pcVar4 = in_ECX;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
    local_8 = 1;
    iVar1 = *(int *)(param_1 + 0xac);
    iVar6 = FUN_00714880(iVar1,*(undefined4 *)(iVar1 + 4),local_30);
    if (*(int *)(param_1 + 0xb0) == 0x9249248) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + 1;
    *(int *)(iVar1 + 4) = iVar6;
    **(int **)(iVar6 + 4) = iVar6;
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    if (500 < *(uint *)(param_1 + 0xb0)) {
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_00403040(**(int **)(param_1 + 0xac) + 8,0,0xffffffff);
      local_8 = 2;
      FUN_00719b20(&local_50,**(undefined4 **)(param_1 + 0xac));
      FUN_007df190(&local_50);
      iVar1 = local_50;
      if (local_50 != *(int *)(param_1 + 0xa0)) {
        if (*(int *)(local_50 + 0x28) != 0) {
          FUN_007b5ec0(*(int *)(local_50 + 0x28));
          *(undefined4 *)(iVar1 + 0x28) = 0;
        }
        FUN_007c2e30(local_54,&local_50,iVar1);
      }
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

