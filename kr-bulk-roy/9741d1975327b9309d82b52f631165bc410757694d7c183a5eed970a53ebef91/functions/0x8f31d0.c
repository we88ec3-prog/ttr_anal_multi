
int FUN_008f31d0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  short sVar4;
  int *unaff_EBX;
  int *piVar5;
  int *piVar6;
  int local_8;
  
  iVar1 = *unaff_EBX;
  uVar2 = *(undefined4 *)(iVar1 + 100);
  *(undefined2 *)(unaff_EBX + 0x4b) = 1;
  unaff_EBX[0x1e] = (uint)*(ushort *)(iVar1 + 0x118);
  unaff_EBX[0x21] = (uint)*(ushort *)(iVar1 + 0x11a);
  unaff_EBX[0x1d] = 0;
  unaff_EBX[0x20] = 0;
  unaff_EBX[0x23] = 0;
  unaff_EBX[0x24] = 0;
  unaff_EBX[0x3c] = *(int *)(iVar1 + 0x284);
  *(undefined2 *)(unaff_EBX + 0x3e) = *(undefined2 *)(iVar1 + 0x116);
  *(undefined2 *)((int)unaff_EBX + 0x6d) = 0;
  unaff_EBX[0x17] = 0;
  unaff_EBX[0x18] = 0;
  unaff_EBX[0x19] = 0;
  unaff_EBX[0x1a] = 0;
  iVar3 = FUN_008bc7d0(uVar2,0x18,0,unaff_EBX[0x1e],0,&local_8);
  unaff_EBX[0x1f] = iVar3;
  if (local_8 == 0) {
    iVar3 = FUN_008bc7d0(uVar2,0x18,0,unaff_EBX[0x21],0,&local_8);
    unaff_EBX[0x22] = iVar3;
    if (local_8 == 0) {
      iVar3 = FUN_008bc7d0(uVar2,4,0,unaff_EBX[0x3c],0,&local_8);
      unaff_EBX[0x3d] = iVar3;
      if (local_8 == 0) {
        iVar3 = FUN_008bc7d0(uVar2,4,0,(short)unaff_EBX[0x3e],0,&local_8);
        unaff_EBX[0x3f] = iVar3;
        if (local_8 == 0) {
          sVar4 = *(short *)(iVar1 + 0x114) + 4;
          local_8 = FUN_008eb740(sVar4,0);
          if (local_8 == 0) {
            *(short *)(unaff_EBX + 0x42) = sVar4;
            piVar5 = &DAT_00bead40;
            piVar6 = unaff_EBX + 0x2b;
            for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
              *piVar6 = *piVar5;
              piVar5 = piVar5 + 1;
              piVar6 = piVar6 + 1;
            }
            iVar3 = *(int *)(*(int *)(*(int *)(iVar1 + 0x60) + 4) + 0xac);
            *(int *)(iVar1 + 0x28c) = iVar3;
            if (iVar3 == 0) {
              *(code **)(iVar1 + 0x28c) = FUN_008ef5a0;
            }
            local_8 = FUN_008f2f70();
            if (local_8 == 0) {
              return 0;
            }
          }
        }
      }
    }
  }
  FUN_008ebb60();
  return local_8;
}

