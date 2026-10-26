
uint FUN_008cad20(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint in_EAX;
  int iVar2;
  int iVar3;
  byte bVar4;
  int in_ECX;
  int iVar5;
  int in_EDX;
  uint uVar6;
  int *piVar7;
  undefined4 *unaff_ESI;
  int iVar8;
  int local_c;
  int local_8;
  
  uVar1 = param_2;
  iVar5 = in_ECX - param_1;
  iVar8 = param_2 - in_EAX;
  if (((0 < iVar8) && (in_EDX <= (int)param_2)) && ((int)in_EAX <= param_3)) {
    if ((int)in_EAX < in_EDX) {
      iVar2 = FUN_008b7dc0(iVar5,in_EDX - in_EAX,iVar8);
      param_1 = param_1 + iVar2;
      bVar4 = (byte)*unaff_ESI;
      local_c = in_EDX >> (bVar4 & 0x1f);
      uVar6 = 0;
    }
    else {
      bVar4 = (byte)*unaff_ESI;
      local_c = (int)in_EAX >> (bVar4 & 0x1f);
      uVar6 = unaff_ESI[1] - 1 & in_EAX;
    }
    if (param_3 < (int)param_2) {
      param_3 = param_3 >> (bVar4 & 0x1f);
      param_2 = 0;
    }
    else {
      param_3 = (int)param_2 >> (bVar4 & 0x1f);
      param_2 = unaff_ESI[1] - 1 & param_2;
    }
    if ((int)uVar6 < 1) {
      if (*(char *)((int)unaff_ESI + 0x57) != '\0') {
        unaff_ESI[10] = unaff_ESI[10] + -4;
        *(undefined1 *)((int)unaff_ESI + 0x57) = 0;
      }
    }
    else {
      in_EAX = uVar1;
      if (local_c == param_3) goto LAB_008cae9e;
      iVar2 = FUN_008b7dc0(iVar5,unaff_ESI[1] - uVar6,iVar8);
      param_1 = param_1 + iVar2;
      local_c = local_c + 1;
    }
    *(bool *)((int)unaff_ESI + 0x57) = param_2 == 0;
    if (*(char *)((int)unaff_ESI + 0x56) != '\0') {
      *(int *)(unaff_ESI[0x16] + 0x14) = local_c;
      *(undefined1 *)((int)unaff_ESI + 0x56) = 0;
    }
    iVar2 = (param_3 - local_c) + 1;
    uVar1 = unaff_ESI[10] + iVar2 * 4;
    if ((uint)unaff_ESI[9] <= uVar1) {
      unaff_ESI[0xb] = 0x62;
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
    if (iVar5 < 1) {
      iVar3 = FUN_008b7e80(unaff_ESI[1],-iVar5,iVar8);
      iVar3 = -iVar3;
      iVar5 = -(unaff_ESI[1] * iVar5);
      local_8 = -1;
    }
    else {
      iVar3 = FUN_008b7e80(unaff_ESI[1],iVar5,iVar8);
      iVar5 = unaff_ESI[1] * iVar5;
      local_8 = 1;
    }
    in_EAX = -iVar8;
    piVar7 = (int *)unaff_ESI[10];
    for (; 0 < iVar2; iVar2 = iVar2 + -1) {
      *piVar7 = param_1;
      piVar7 = piVar7 + 1;
      param_1 = param_1 + iVar3;
      in_EAX = in_EAX + iVar5 % iVar8;
      if (-1 < (int)in_EAX) {
        in_EAX = in_EAX - iVar8;
        param_1 = param_1 + local_8;
      }
    }
    unaff_ESI[10] = piVar7;
  }
LAB_008cae9e:
  return in_EAX & 0xffffff00;
}

