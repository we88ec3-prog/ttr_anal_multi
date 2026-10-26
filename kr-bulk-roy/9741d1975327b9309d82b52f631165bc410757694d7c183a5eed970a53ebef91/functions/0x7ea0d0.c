
void FUN_007ea0d0(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 ****ppppuVar8;
  int local_174;
  undefined1 local_170 [28];
  undefined4 local_154;
  uint local_140;
  undefined4 ***local_138 [4];
  undefined4 local_128;
  uint local_124;
  char local_11c [264];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  local_8 = 0xff;
  uStack_7 = 0xffffff;
  puStack_c = &LAB_0092257d;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (param_2 != 0) {
    pcVar3 = (char *)(param_1 + 8);
    if (0xf < *(uint *)(param_1 + 0x1c)) {
      pcVar3 = *(char **)pcVar3;
    }
    __splitpath(pcVar3,(char *)0x0,(char *)0x0,local_11c,(char *)0x0);
    pcVar3 = local_11c;
    local_124 = 0xf;
    local_128 = 0;
    local_138[0] = (undefined4 ***)((uint)local_138[0] & 0xffffff00);
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(local_11c,(int)pcVar3 - (int)(local_11c + 1));
    local_8 = 0;
    uStack_7 = 0;
    FUN_00401fc0(&DAT_00c50568,4);
    ppppuVar8 = (undefined4 ****)local_138[0];
    if (local_124 < 0x10) {
      ppppuVar8 = local_138;
    }
    if ((DAT_00fe1df8 & 1) == 0) {
      DAT_00fe1df8 = DAT_00fe1df8 | 1;
      local_8 = 1;
      FUN_00716be0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcf1a0);
      local_8 = 0;
    }
    iVar4 = FUN_00716740(ppppuVar8);
    puVar5 = (undefined4 *)FUN_0079c590();
    local_8 = 2;
    if (0xf < (uint)puVar5[5]) {
      puVar5 = (undefined4 *)*puVar5;
    }
    uVar6 = FUN_00714770(puVar5,&DAT_00bed1e0);
    local_8 = 0;
    *(undefined4 *)(param_1 + 0x24) = uVar6;
    if (0xf < local_140) {
      FUN_0089120c(local_154);
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      iVar7 = FUN_00891268(0x118);
      if (iVar7 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_007e4b90();
      }
      *(undefined4 *)(param_1 + 0x28) = uVar6;
      if (*(int **)(param_1 + 0x24) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x24) + 0x10))(uVar6,0x118,1);
      }
    }
    local_174 = iVar4 + 0x1c;
    if (0xf < *(uint *)(iVar4 + 0x30)) {
      local_174 = *(int *)local_174;
    }
    if ((DAT_00fe3314 & 1) == 0) {
      DAT_00fe3314 = DAT_00fe3314 | 1;
      local_8 = 3;
      FUN_007ed9f0();
      _atexit((_func_4879 *)&LAB_00bd0ae0);
      local_8 = 0;
    }
    if (DAT_00fe3318 != 0) {
      FUN_007ed8d0(local_170,local_174);
      local_8 = 4;
      FUN_007edcd0();
      local_8 = 0;
      FUN_007ee080();
    }
    uVar6 = FUN_0072e2e0("Height");
    FUN_007ea3a0(param_1,uVar6);
    FUN_0072e2e0("Layer");
    FUN_007ea5f0(param_1);
    FUN_0072e2e0("LightMap");
    FUN_007eaa90();
    if (*(int *)(param_1 + 0x24) != 0) {
      if (*(int *)(param_1 + 0x28) != 0) {
        FUN_0089120c(*(int *)(param_1 + 0x28));
        *(undefined4 *)(param_1 + 0x28) = 0;
      }
      if (*(int **)(param_1 + 0x24) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x24) + 4))();
      }
    }
    if (0xf < local_124) {
      FUN_0089120c(local_138[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

