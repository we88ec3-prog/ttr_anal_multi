
int FUN_006fe770(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_EAX;
  int iVar6;
  undefined4 *puVar7;
  undefined4 in_EDX;
  
  uVar2 = *(undefined2 *)(in_EAX + 0x34);
  uVar1 = *(undefined1 *)(in_EAX + 0x39);
  iVar3 = *(int *)(in_EAX + 0x14);
  iVar4 = *(int *)(in_EAX + 0x28);
  uVar5 = *(undefined4 *)(in_EAX + 0x74);
  *(undefined4 *)(in_EAX + 0x74) = in_EDX;
  iVar6 = FUN_006fdba0();
  if (iVar6 == 0) {
    *(undefined4 *)(in_EAX + 0x74) = uVar5;
    return 0;
  }
  FUN_006fd860(*(int *)(in_EAX + 0x20) + param_3);
  FUN_006fda60();
  puVar7 = (undefined4 *)((iVar3 - iVar4) + *(int *)(in_EAX + 0x28));
  *(undefined2 *)(in_EAX + 0x34) = uVar2;
  *(undefined4 **)(in_EAX + 0x14) = puVar7;
  *(undefined4 *)(in_EAX + 0xc) = *puVar7;
  *(undefined4 *)(in_EAX + 0x18) = puVar7[3];
  *(undefined1 *)(in_EAX + 0x39) = uVar1;
  if (20000 < *(int *)(in_EAX + 0x30)) {
    if (((int)puVar7 - *(int *)(in_EAX + 0x28)) / 0x18 + 1 < 20000) {
      FUN_006fdd10();
      *(undefined4 *)(in_EAX + 0x74) = uVar5;
      return iVar6;
    }
    *(undefined4 *)(in_EAX + 0x74) = uVar5;
    return iVar6;
  }
  *(undefined4 *)(in_EAX + 0x74) = uVar5;
  return iVar6;
}

