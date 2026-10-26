
void FUN_007dc660(undefined4 *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *in_ECX;
  int unaff_ESI;
  undefined1 auStack_68 [4];
  undefined4 *local_64;
  int local_60 [2];
  uint local_58 [4];
  undefined4 local_48;
  uint local_44;
  uint local_3c [4];
  undefined4 local_2c;
  uint local_28;
  undefined4 *local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00914970;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_68;
  ExceptionList = &local_14;
  local_64 = param_1;
  iVar3 = FUN_007dca10(DAT_00d61f20 ^ (uint)&stack0xffffff90);
  if (iVar3 == 0) {
    local_28 = 0xf;
    local_2c = 0;
    local_3c[0] = local_3c[0] & 0xffffff00;
    pcVar4 = in_ECX;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
    local_20 = local_64;
    local_c = 0;
    iVar3 = **(int **)(unaff_ESI + 4);
    iVar5 = FUN_00719b90(iVar3,*(undefined4 *)(iVar3 + 4),local_3c);
    if (*(int *)(unaff_ESI + 8) == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 1;
    *(int *)(iVar3 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    FUN_007d1080(local_60,**(int **)(unaff_ESI + 4) + 8,**(int **)(unaff_ESI + 4));
    if (0xf < local_28) {
      FUN_0089120c(local_3c[0]);
    }
  }
  else {
    local_44 = 0xf;
    local_48 = 0;
    local_58[0] = local_58[0] & 0xffffff00;
    pcVar4 = in_ECX;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
    local_c = 1;
    FUN_007b86f0(local_60,local_58);
    local_c = 0xffffffff;
    if (0xf < local_44) {
      FUN_0089120c(local_58[0]);
    }
    piVar1 = (int *)(*(int *)(local_60[0] + 0x24) + 8);
    *piVar1 = *piVar1 + 1;
    local_44 = 0xf;
    local_48 = 0;
    local_58[0] = local_58[0] & 0xffffff00;
    if (local_64 != (undefined4 *)0x0) {
      (**(code **)*local_64)(1);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_68);
  return;
}

