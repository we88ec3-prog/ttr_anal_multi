
void FUN_0052d110(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_EAX;
  int iVar3;
  uint *unaff_ESI;
  bool bVar4;
  
  iVar3 = FUN_0052d410(unaff_ESI);
  if (iVar3 != *(int *)(in_EAX + 4)) {
    uVar1 = unaff_ESI[1];
    uVar2 = *(uint *)(iVar3 + 0x14);
    if ((*unaff_ESI == *(uint *)(iVar3 + 0x10)) && (uVar1 == uVar2)) {
      if (unaff_ESI[3] < *(uint *)(iVar3 + 0x1c)) goto LAB_0052d16e;
      if (unaff_ESI[3] != *(uint *)(iVar3 + 0x1c)) goto LAB_0052d15c;
      bVar4 = unaff_ESI[2] < *(uint *)(iVar3 + 0x18);
    }
    else {
      if (uVar1 < uVar2) goto LAB_0052d16e;
      if (uVar1 != uVar2) goto LAB_0052d15c;
      bVar4 = *unaff_ESI < *(uint *)(iVar3 + 0x10);
    }
    if (!bVar4) {
LAB_0052d15c:
      *param_1 = iVar3;
      return;
    }
  }
LAB_0052d16e:
  *param_1 = *(int *)(in_EAX + 4);
  return;
}

