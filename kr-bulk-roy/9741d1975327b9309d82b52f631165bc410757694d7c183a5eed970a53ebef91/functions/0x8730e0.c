
int * FUN_008730e0(int *param_1,undefined4 param_2)

{
  char *pcVar1;
  char cVar2;
  void **ppvVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *in_ECX;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00908c58;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  for (; ExceptionList = ppvVar3, in_ECX != param_1; in_ECX = in_ECX + 1) {
    iVar8 = *in_ECX;
    if (*(uint *)(iVar8 + 0x1c) < 0x10) {
      pcVar5 = (char *)(iVar8 + 8);
    }
    else {
      pcVar5 = *(char **)(iVar8 + 8);
    }
    pcVar1 = pcVar5 + 1;
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    uVar6 = (int)pcVar5 - (int)pcVar1;
    uVar7 = in_stack_00000018;
    if (uVar6 <= in_stack_00000018) {
      uVar7 = uVar6;
    }
    iVar8 = FUN_00407e70(uVar7,uVar4);
    if (((iVar8 == 0) && (uVar6 <= in_stack_00000018)) && (in_stack_00000018 == uVar6)) break;
    ppvVar3 = ExceptionList;
  }
  if (0xf < in_stack_0000001c) {
    FUN_0089120c(param_2);
  }
  ExceptionList = local_10;
  return in_ECX;
}

