
void FUN_004cbff0(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  undefined4 *local_8;
  
  FUN_004ca730();
  in_EAX[0x43] = param_1;
  in_EAX[0x3c] = 0;
  *in_EAX = CBullet::vftable;
  in_EAX[0x3d] = 0;
  in_EAX[0x3e] = 0;
  in_EAX[0x3f] = 0;
  in_EAX[0x44] = 0;
  in_EAX[0x45] = 0;
  in_EAX[0x46] = 0;
  in_EAX[0x47] = 0;
  in_EAX[0x48] = 0;
  in_EAX[0x49] = 0;
  in_EAX[0x4d] = 0;
  cVar1 = *(char *)((int)DAT_00fbaae8[1] + 0xa1);
  puVar3 = (undefined4 *)DAT_00fbaae8[1];
  puVar2 = DAT_00fbaae8;
  while (puVar5 = puVar3, cVar1 == '\0') {
    if (*(ushort *)(puVar5 + 3) < *(ushort *)(in_EAX + 0x43)) {
      puVar3 = (undefined4 *)puVar5[2];
      puVar5 = puVar2;
    }
    else {
      puVar3 = (undefined4 *)*puVar5;
    }
    cVar1 = *(char *)((int)puVar3 + 0xa1);
    puVar2 = puVar5;
  }
  if ((puVar2 == DAT_00fbaae8) || (*(ushort *)(in_EAX + 0x43) < *(ushort *)(puVar2 + 3))) {
    local_8 = DAT_00fbaae8;
    ppuVar4 = &local_8;
  }
  else {
    ppuVar4 = &param_1;
  }
  puVar3 = *ppuVar4;
  if (puVar3 != DAT_00fbaae8) {
    in_EAX[0x48] = puVar3[0x25];
    in_EAX[0x47] = puVar3[0x24];
  }
  return;
}

