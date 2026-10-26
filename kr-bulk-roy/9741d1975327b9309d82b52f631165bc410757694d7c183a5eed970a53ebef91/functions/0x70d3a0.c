
undefined4 * FUN_0070d3a0(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 uStack_d;
  int local_c [2];
  
  local_c[0] = *param_1;
  iVar3 = *(int *)(local_c[0] + 0x10);
  puVar2 = (undefined4 *)(**(code **)(iVar3 + 0xc))(*(undefined4 *)(iVar3 + 0x10),0,0,0x4c);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_006fdb40(local_c[0],4);
  }
  *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + 0x4c;
  iVar3 = *(int *)(local_c[0] + 0x10);
  *puVar2 = *(undefined4 *)(iVar3 + 0x1c);
  *(undefined4 **)(iVar3 + 0x1c) = puVar2;
  *(byte *)((int)puVar2 + 5) = *(byte *)(iVar3 + 0x14) & 3;
  puVar2[2] = 0;
  puVar2[10] = 0;
  puVar2[4] = 0;
  puVar2[0xd] = 0;
  puVar2[3] = 0;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0;
  puVar2[9] = 0;
  puVar2[7] = 0;
  puVar2[0x12] = 0;
  puVar2[5] = 0;
  puVar2[0xe] = 0;
  puVar2[6] = 0;
  puVar2[0xf] = 0;
  puVar2[0x10] = 0;
  puVar2[8] = 0;
  *(undefined1 *)(puVar2 + 1) = 9;
  puVar1 = *(undefined4 **)(*param_1 + 8);
  *puVar1 = puVar2;
  puVar1[2] = 9;
  if (*(int *)(*param_1 + 0x1c) - *(int *)(*param_1 + 8) < 0x11) {
    FUN_006fdcb0();
  }
  *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + 0x10;
  iVar3 = FUN_0070cc40(param_1);
  puVar2[8] = iVar3;
  if (iVar3 == 0) {
    puVar2[8] = param_2;
  }
  iVar3 = FUN_006fee90(local_c,4);
  if (iVar3 != 0) {
    FUN_0070cc10();
  }
  iVar3 = local_c[0];
  if (local_c[0] < 0) {
    iVar3 = FUN_0070cc10();
  }
  puVar2[0xf] = iVar3;
  iVar3 = FUN_006fee90(local_c,4);
  if (iVar3 != 0) {
    FUN_0070cc10();
  }
  iVar3 = local_c[0];
  if (local_c[0] < 0) {
    iVar3 = FUN_0070cc10();
  }
  puVar2[0x10] = iVar3;
  iVar3 = FUN_006fee90(&uStack_d,1);
  if (iVar3 != 0) {
    FUN_0070cc10();
  }
  *(undefined1 *)(puVar2 + 0x12) = uStack_d;
  iVar3 = FUN_006fee90(&uStack_d,1);
  if (iVar3 != 0) {
    FUN_0070cc10();
  }
  *(undefined1 *)((int)puVar2 + 0x49) = uStack_d;
  iVar3 = FUN_006fee90(&uStack_d,1);
  if (iVar3 != 0) {
    FUN_0070cc10();
  }
  *(undefined1 *)((int)puVar2 + 0x4a) = uStack_d;
  iVar3 = FUN_006fee90(&uStack_d,1);
  if (iVar3 != 0) {
    FUN_0070cc10();
  }
  *(undefined1 *)((int)puVar2 + 0x4b) = uStack_d;
  FUN_0070ccc0(param_1,puVar2);
  FUN_0070cda0(param_1,puVar2);
  FUN_0070d070(param_1);
  iVar3 = FUN_006f82d0(puVar2,puVar2[0xb],0xff);
  if (iVar3 == 0) {
    FUN_0070cc10();
  }
  *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + -0x10;
  return puVar2;
}

