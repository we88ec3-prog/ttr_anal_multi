
void FUN_0070dfb0(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *in_EAX;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  iVar2 = *(int *)(param_1 + 0x34);
  iVar3 = *(int *)(iVar2 + 0x10);
  puVar5 = (undefined4 *)(**(code **)(iVar3 + 0xc))(*(undefined4 *)(iVar3 + 0x10),0,0,0x4c);
  if (puVar5 == (undefined4 *)0x0) {
    FUN_006fdb40(iVar2,4);
  }
  *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + 0x4c;
  iVar3 = *(int *)(iVar2 + 0x10);
  *puVar5 = *(undefined4 *)(iVar3 + 0x1c);
  *(undefined4 **)(iVar3 + 0x1c) = puVar5;
  bVar1 = *(byte *)(iVar3 + 0x14);
  puVar5[0x12] = 0;
  puVar5[8] = 0;
  *(undefined1 *)(puVar5 + 1) = 9;
  puVar5[2] = 0;
  puVar5[10] = 0;
  puVar5[4] = 0;
  puVar5[0xd] = 0;
  puVar5[3] = 0;
  puVar5[0xb] = 0;
  puVar5[0xc] = 0;
  puVar5[9] = 0;
  puVar5[7] = 0;
  puVar5[5] = 0;
  puVar5[0xe] = 0;
  puVar5[6] = 0;
  puVar5[0xf] = 0;
  puVar5[0x10] = 0;
  *(byte *)((int)puVar5 + 5) = bVar1 & 3;
  *in_EAX = puVar5;
  in_EAX[2] = *(undefined4 *)(param_1 + 0x30);
  in_EAX[3] = param_1;
  in_EAX[4] = iVar2;
  *(undefined4 **)(param_1 + 0x30) = in_EAX;
  in_EAX[7] = 0xffffffff;
  in_EAX[8] = 0xffffffff;
  in_EAX[6] = 0;
  in_EAX[9] = 0;
  in_EAX[10] = 0;
  in_EAX[0xb] = 0;
  *(undefined2 *)(in_EAX + 0xc) = 0;
  *(undefined1 *)((int)in_EAX + 0x32) = 0;
  in_EAX[5] = 0;
  puVar5[8] = *(undefined4 *)(param_1 + 0x40);
  *(undefined1 *)((int)puVar5 + 0x4b) = 2;
  uVar6 = FUN_006f99a0(iVar2,0,0);
  in_EAX[1] = uVar6;
  puVar4 = *(undefined4 **)(iVar2 + 8);
  *puVar4 = uVar6;
  puVar4[2] = 5;
  if (*(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 8) < 0x11) {
    FUN_006fdcb0();
  }
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 0x10;
  puVar4 = *(undefined4 **)(iVar2 + 8);
  *puVar4 = puVar5;
  puVar4[2] = 9;
  if (*(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 8) < 0x11) {
    if (0 < *(int *)(iVar2 + 0x2c)) {
      FUN_006fdcb0();
      *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 0x10;
      return;
    }
    FUN_006fdcb0();
  }
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 0x10;
  return;
}

