
undefined4 FUN_007851e0(undefined4 param_1)

{
  uint uVar1;
  uint *in_EAX;
  undefined4 *puVar2;
  int iVar3;
  int *unaff_ESI;
  
  uVar1 = *in_EAX;
  if (uVar1 == 0) {
    return 0;
  }
  if ((uVar1 & 2) == 0) {
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 8) == 0) goto LAB_0078526e;
      iVar3 = FUN_00891268(0x28);
      if (iVar3 == 0) goto LAB_0078526a;
      puVar2 = (undefined4 *)FUN_00784a10();
    }
    else {
      iVar3 = FUN_00891268(0x28);
      if (iVar3 == 0) goto LAB_0078526a;
      puVar2 = (undefined4 *)FUN_00785cf0();
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_00891268(0x24);
    if (puVar2 == (undefined4 *)0x0) {
LAB_0078526a:
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2[2] = gbORT::vftable;
      puVar2[3] = 1;
      puVar2[4] = 1;
      *puVar2 = gbLinTrack<gbQuat>::vftable;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[1] = 2;
    }
  }
  *unaff_ESI = (int)puVar2;
LAB_0078526e:
  if ((int *)*unaff_ESI == (int *)0x0) {
    return 0;
  }
  (**(code **)(*(int *)*unaff_ESI + 0x14))(param_1);
  FUN_007912b0(*unaff_ESI);
  return 1;
}

