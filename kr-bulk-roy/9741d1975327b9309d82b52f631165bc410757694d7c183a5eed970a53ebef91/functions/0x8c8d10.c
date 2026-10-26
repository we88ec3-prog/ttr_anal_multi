
int FUN_008c8d10(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  int *unaff_ESI;
  uint uVar6;
  
  puVar1 = (uint *)unaff_ESI[2];
  iVar2 = 0;
  if ((char)unaff_ESI[4] == '\0') {
    return 6;
  }
  uVar6 = (uint)*(ushort *)unaff_ESI[3];
  puVar1[1] = (uint)((ushort *)unaff_ESI[3])[1];
  *puVar1 = uVar6;
  switch(*(undefined1 *)((int)unaff_ESI + 0x12)) {
  case 1:
    puVar1[2] = (int)(puVar1[1] + 7) >> 3;
    *(undefined1 *)((int)puVar1 + 0x12) = 1;
    uVar4 = 2;
    break;
  case 2:
    puVar1[2] = (int)(puVar1[1] + 3) >> 2;
    *(undefined1 *)((int)puVar1 + 0x12) = 3;
    uVar4 = 4;
    break;
  default:
    return 3;
  case 4:
    puVar1[2] = (int)(puVar1[1] + 1) >> 1;
    *(undefined1 *)((int)puVar1 + 0x12) = 4;
    uVar4 = 0x10;
    break;
  case 8:
    uVar5 = puVar1[1];
    *(undefined1 *)((int)puVar1 + 0x12) = 2;
    goto LAB_008c8da2;
  case 0x20:
    *(undefined1 *)((int)puVar1 + 0x12) = 7;
    uVar5 = puVar1[1] * 4;
LAB_008c8da2:
    puVar1[2] = uVar5;
    uVar4 = 0x100;
  }
  *(undefined2 *)(puVar1 + 4) = uVar4;
  iVar3 = puVar1[2] * uVar6;
  if ((iVar3 != 0) && (iVar2 = FUN_008bb1d0(*(undefined4 *)(*unaff_ESI + 0x54),iVar3), iVar2 == 0))
  {
    *(undefined1 *)((int)unaff_ESI + 0x11) = 1;
    return 0;
  }
  return iVar2;
}

