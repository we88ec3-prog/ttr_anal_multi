
void FUN_00725a80(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *unaff_EDI;
  bool bVar6;
  
  puVar4 = unaff_EDI;
joined_r0x00725a8e:
  do {
    puVar3 = puVar4 + 2;
    if (puVar3 == param_1) {
      return;
    }
    uVar1 = puVar4[3];
    uVar2 = *puVar3;
    puVar5 = puVar3;
    if (uVar1 == 0) {
      if (unaff_EDI[1] != 0) goto LAB_00725ada;
      bVar6 = uVar2 < *unaff_EDI;
LAB_00725ab3:
      if (!bVar6) {
LAB_00725ada:
        puVar4 = puVar4 + 1;
        do {
          if (uVar1 == 0) {
            if (*puVar4 != 0) goto LAB_00725b15;
            bVar6 = uVar2 < puVar4[-1];
LAB_00725af6:
            if (!bVar6) goto LAB_00725b15;
          }
          else if (*puVar4 != 0) {
            bVar6 = uVar1 < *puVar4;
            goto LAB_00725af6;
          }
          *puVar5 = puVar4[-1];
          puVar5[1] = *puVar4;
          puVar5 = puVar5 + -2;
          puVar4 = puVar4 + -2;
        } while( true );
      }
    }
    else if (unaff_EDI[1] != 0) {
      bVar6 = uVar1 < unaff_EDI[1];
      goto LAB_00725ab3;
    }
    for (; unaff_EDI != puVar5; puVar5 = puVar5 + -2) {
      *puVar5 = puVar5[-2];
      puVar5[1] = puVar5[-1];
    }
    *unaff_EDI = uVar2;
    unaff_EDI[1] = uVar1;
    puVar4 = puVar3;
  } while( true );
LAB_00725b15:
  *puVar5 = uVar2;
  puVar5[1] = uVar1;
  puVar4 = puVar3;
  goto joined_r0x00725a8e;
}

