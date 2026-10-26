
int FUN_008f1f40(int param_1,char param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x8c);
  if (iVar2 != 0) {
    FID_conflict__memcpy
              (*(void **)(param_1 + 0x88),*(void **)(param_1 + 0x8c),
               (uint)*(ushort *)(param_1 + 0x84) * 8);
  }
  puVar4 = (undefined4 *)(*(int *)(param_1 + 4) + 0xac);
  puVar5 = (undefined4 *)(*(int *)(param_1 + 0xa0) + 0x11c);
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if (param_2 == '\0') {
    *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xdc) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x30)
    ;
    *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xe0) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x34)
    ;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xdc) = 0x10000;
    *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xe0) = 0x10000;
    FID_conflict__memcpy
              (*(void **)(param_1 + 0x90),*(void **)(param_1 + 0x8c),
               (uint)*(ushort *)(param_1 + 0x84) * 8);
  }
  *(uint *)(*(int *)(param_1 + 0x8c) + -0x20 + (uint)*(ushort *)(param_1 + 0x84) * 8) =
       *(int *)(*(int *)(param_1 + 0x8c) + -0x20 + (uint)*(ushort *)(param_1 + 0x84) * 8) + 0x20U &
       0xffffffc0;
  *(uint *)(*(int *)(param_1 + 0x8c) + -0x18 + (uint)*(ushort *)(param_1 + 0x84) * 8) =
       *(int *)(*(int *)(param_1 + 0x8c) + -0x18 + (uint)*(ushort *)(param_1 + 0x84) * 8) + 0x20U &
       0xffffffc0;
  *(uint *)(*(int *)(param_1 + 0x8c) + -0xc + (uint)*(ushort *)(param_1 + 0x84) * 8) =
       *(int *)(*(int *)(param_1 + 0x8c) + -0xc + (uint)*(ushort *)(param_1 + 0x84) * 8) + 0x20U &
       0xffffffc0;
  *(uint *)(*(int *)(param_1 + 0x8c) + -4 + (uint)*(ushort *)(param_1 + 0x84) * 8) =
       *(int *)(*(int *)(param_1 + 0x8c) + -4 + (uint)*(ushort *)(param_1 + 0x84) * 8) + 0x20U &
       0xffffffc0;
  if (iVar2 != 0) {
    pbVar1 = *(byte **)(*(int *)(param_1 + 0xc) + 0x40);
    iVar2 = FUN_008ebea0(iVar2);
    if (iVar2 != 0) {
      return iVar2;
    }
    *(char *)(*(int *)(param_1 + 0xa0) + 0x230) = param_2;
    puVar4 = (undefined4 *)(param_1 + 0x7c);
    puVar5 = (undefined4 *)(*(int *)(param_1 + 0xa0) + 0x90);
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar2 = FUN_008ec2a0();
    if ((iVar2 != 0) && (*(char *)(*(int *)(param_1 + 0xa0) + 0x231) != '\0')) {
      return iVar2;
    }
    *pbVar1 = *pbVar1 | *(char *)(*(int *)(param_1 + 0xa0) + 0x154) << 5 | 4U;
  }
  *(undefined4 *)(param_1 + 0x44) =
       *(undefined4 *)(*(int *)(param_1 + 0x8c) + -0x20 + (uint)*(ushort *)(param_1 + 0x84) * 8);
  *(undefined4 *)(param_1 + 0x48) =
       *(undefined4 *)(*(int *)(param_1 + 0x8c) + -0x1c + (uint)*(ushort *)(param_1 + 0x84) * 8);
  *(undefined4 *)(param_1 + 0x4c) =
       *(undefined4 *)(*(int *)(param_1 + 0x8c) + -0x18 + (uint)*(ushort *)(param_1 + 0x84) * 8);
  *(undefined4 *)(param_1 + 0x50) =
       *(undefined4 *)(*(int *)(param_1 + 0x8c) + -0x14 + (uint)*(ushort *)(param_1 + 0x84) * 8);
  *(undefined4 *)(param_1 + 0xb8) =
       *(undefined4 *)(*(int *)(param_1 + 0x8c) + -0x10 + (uint)*(ushort *)(param_1 + 0x84) * 8);
  *(undefined4 *)(param_1 + 0xbc) =
       *(undefined4 *)(*(int *)(param_1 + 0x8c) + -0xc + (uint)*(ushort *)(param_1 + 0x84) * 8);
  *(undefined4 *)(param_1 + 0xc0) =
       *(undefined4 *)(*(int *)(param_1 + 0x8c) + -8 + (uint)*(ushort *)(param_1 + 0x84) * 8);
  *(undefined4 *)(param_1 + 0xc4) =
       *(undefined4 *)(*(int *)(param_1 + 0x8c) + -4 + (uint)*(ushort *)(param_1 + 0x84) * 8);
  return 0;
}

