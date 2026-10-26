
void FUN_00458be0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined1 local_214 [512];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f5fe;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0045f0c0(local_14);
  iVar5 = 0;
  piVar6 = (int *)(in_ECX + 0x80);
  do {
    FUN_0046b6f0(iVar5 + 0x7d1);
    iVar2 = *piVar6;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar2 + 0xa4) = 1;
    iVar2 = *piVar6;
    if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
       (iVar3 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar3 == 0xbf6b)) {
      *(undefined1 *)(*(int *)(iVar2 + 0x94) + 0x4c) = 1;
    }
    iVar5 = iVar5 + 1;
    piVar6 = piVar6 + 1;
  } while (iVar5 < 10);
  iVar5 = 0x834;
  do {
    FUN_0046b6f0(iVar5);
    iVar5 = iVar5 + 100;
  } while (iVar5 < 0x960);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  puVar7 = *(undefined4 **)(*(int *)(DAT_00f943ac + 8) + 4);
  cVar1 = *(char *)((int)puVar7 + 0x15);
  while (cVar1 == '\0') {
    if ((uint)puVar7[3] < 0x4b) {
      puVar7 = (undefined4 *)puVar7[2];
    }
    else {
      puVar7 = (undefined4 *)*puVar7;
    }
    cVar1 = *(char *)((int)puVar7 + 0x15);
  }
  iVar5 = 0;
  puVar7 = (undefined4 *)(in_ECX + 0xa8);
  do {
    FUN_0040aeb0(&DAT_00bfe148,iVar5);
    uVar4 = FUN_00763360(local_214);
    *puVar7 = uVar4;
    iVar5 = iVar5 + 1;
    puVar7 = puVar7 + 1;
  } while (iVar5 < 10);
  *(undefined4 *)(in_ECX + 0xe4) = 0xffffff6b;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

