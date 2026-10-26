
/* WARNING: Removing unreachable block (ram,0x00866aa8) */
/* WARNING: Removing unreachable block (ram,0x00866abd) */
/* WARNING: Removing unreachable block (ram,0x00866ab6) */
/* WARNING: Removing unreachable block (ram,0x00866aaf) */
/* WARNING: Removing unreachable block (ram,0x00866ac9) */
/* WARNING: Removing unreachable block (ram,0x00866ace) */
/* WARNING: Removing unreachable block (ram,0x00866ad3) */
/* WARNING: Recovered jumptable eliminated as dead code */

void FUN_00866930(int param_1)

{
  int *piVar1;
  undefined4 ***pppuVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int in_ECX;
  uint uStack_6c;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  undefined4 local_48;
  undefined4 local_44 [2];
  int local_3c;
  undefined4 **local_38;
  uint uStack_34;
  uint uStack_2c;
  int local_28;
  void *local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00920420;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_5c;
  uStack_6c = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  piVar1 = (int *)(in_ECX + 0x184);
  local_3c = param_1;
  FUN_0085e020(piVar1,&local_48,*(undefined4 *)(in_ECX + 0x184),*(undefined4 *)(in_ECX + 0x188));
  FUN_008445a0(param_1);
  local_24 = (void *)0xf;
  local_28 = 0;
  local_38 = (undefined4 **)((uint)local_38 & 0xffffff00);
  local_c = 0;
  FUN_00781ea0();
  if (local_28 != 0) {
    pppuVar2 = (undefined4 ***)local_38;
    if (local_24 < (void *)0x10) {
      pppuVar2 = &local_38;
    }
    puVar3 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0x90) + 0x7c))(&local_48,pppuVar2);
    *(undefined4 *)(in_ECX + 0x16c) = *puVar3;
  }
  local_44[0] = 0;
  FUN_006ddcc0(*(undefined4 *)(local_3c + 0x84),local_44,4,0);
  FUN_0085e020(piVar1,&iStack_58,*piVar1,*(undefined4 *)(in_ECX + 0x188));
  FUN_00866d70();
  iStack_58 = 0;
  if (0 < iStack_54) {
    iStack_50 = 0;
    do {
      iStack_5c = 0;
      local_1c = CONCAT31(local_1c._1_3_,1);
      iVar4 = FUN_00868490(&stack0xffffff98);
      if ((iVar4 != 0) && (puVar5 = (undefined1 *)(*piVar1 + iStack_50), puVar5 != &stack0xffffff98)
         ) {
        if (*(int *)(puVar5 + 4) == 0) {
          *(undefined4 *)(puVar5 + 4) = 0;
        }
        FUN_00867fd0(puVar5,&stack0xffffff98);
      }
      local_1c = local_1c & 0xffffff00;
      if (iStack_5c != 0) {
        FUN_00891d3d(iStack_5c);
        iStack_5c = 0;
      }
      iStack_50 = iStack_50 + 0x10;
      iStack_58 = iStack_58 + 1;
    } while (iStack_58 < iStack_54);
  }
  if (0xf < uStack_34) {
    FUN_0089120c(local_48);
  }
  ExceptionList = local_24;
  __security_check_cookie(uStack_2c ^ (uint)&uStack_6c);
  return;
}

