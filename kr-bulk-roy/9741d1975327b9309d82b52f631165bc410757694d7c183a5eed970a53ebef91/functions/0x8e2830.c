
undefined4 FUN_008e2830(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar3;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int iVar4;
  int *piVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  iVar1 = *(int *)(in_EAX + 0x14);
  if (*(int *)(in_EAX + 4) == 0) {
    return 0;
  }
  iVar4 = in_EAX + 0x44;
  do {
    if (*(char *)(iVar4 + 0x10) == '\0') {
LAB_008e287e:
      lVar7 = FUN_008e0ee0();
      piVar5 = (int *)((ulonglong)lVar7 >> 0x20);
      iVar3 = extraout_ECX_00;
      if ((char)lVar7 != '\0') {
        iVar4 = *(int *)(param_2 + 8);
        lVar7 = CONCAT44(piVar5,iVar4);
        if ((*piVar5 - iVar1 <= iVar4) &&
           (lVar7 = CONCAT44(piVar5,iVar4), iVar4 <= piVar5[1] + iVar1)) {
LAB_008e295e:
          cVar2 = FUN_008e0eb0();
          if (cVar2 != '\0') {
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + extraout_ECX_01;
            FUN_008e0f20();
          }
          uVar6 = FUN_008e0eb0();
          if ((char)uVar6 != '\0') {
            piVar5 = (int *)((int)((ulonglong)uVar6 >> 0x20) + 0xc);
            *piVar5 = *piVar5 + extraout_ECX_02;
            FUN_008e0f20();
          }
          return 1;
        }
      }
    }
    else {
      uVar6 = FUN_008e0ef0();
      piVar5 = (int *)((ulonglong)uVar6 >> 0x20);
      if ((((char)uVar6 != '\0') && (*piVar5 - iVar1 <= *(int *)(param_1 + 8))) &&
         (*(int *)(param_1 + 8) <= piVar5[1] + iVar1)) goto LAB_008e295e;
      iVar3 = extraout_ECX;
      lVar7 = ZEXT48(piVar5) << 0x20;
      if ((char)piVar5[4] == '\0') goto LAB_008e287e;
    }
    iVar4 = (int)((ulonglong)lVar7 >> 0x20) + 0x14;
    if (*(uint *)(in_EAX + 4) <= iVar3 + 1U) {
      return 0;
    }
  } while( true );
}

