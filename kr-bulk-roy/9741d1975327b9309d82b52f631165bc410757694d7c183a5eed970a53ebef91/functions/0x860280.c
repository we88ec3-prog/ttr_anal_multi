
undefined4 FUN_00860280(int param_1)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  undefined1 local_1c [8];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00920488;
  local_14 = ExceptionList;
  pvVar2 = (void *)(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_14;
  FUN_00860810(in_ECX + 0x78,local_1c,*(undefined4 *)(in_ECX + 0x78),*(undefined4 *)(in_ECX + 0x7c))
  ;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0xa8) = 1;
  FUN_00780260(param_1);
  uVar6 = in_ECX + 0x54;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),uVar6,0x1c,0);
  uVar3 = FUN_00781f20();
  *(undefined4 *)(in_ECX + 0x74) = uVar3;
  FUN_00872580(uVar3,0x10);
  FUN_00872580(*(undefined4 *)(in_ECX + 0x74),0x101);
  uVar5 = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&stack0xffffffd0,4,0);
  if (uVar6 != 0) {
    do {
      puVar4 = (undefined4 *)FUN_00781f20();
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[1] = puVar4[1] + 1;
      }
      FUN_0077f8f0();
      if (puVar4 != (undefined4 *)0x0) {
        piVar1 = puVar4 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)*puVar4)(1);
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar6);
  }
  ExceptionList = pvVar2;
  return 1;
}

