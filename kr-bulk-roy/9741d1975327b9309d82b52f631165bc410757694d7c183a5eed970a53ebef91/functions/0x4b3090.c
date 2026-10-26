
undefined4 FUN_004b3090(uint param_1,uint param_2)

{
  ushort uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  undefined4 *puVar8;
  
  if (param_2 < 2) {
    uVar7 = 0;
  }
  else {
    uVar7 = (param_2 - 2) / 0x12;
  }
  if (uVar7 != 0) {
    puVar8 = (undefined4 *)(param_1 + 8);
    param_1 = uVar7;
    do {
      param_2 = (uint)*(ushort *)((int)puVar8 + -2);
      iVar5 = FUN_0040f060();
      FUN_0082ef00(&param_2);
      if ((in_ECX != *(int *)(iVar5 + 0xc)) &&
         (piVar2 = *(int **)(in_ECX + 0x10), piVar2 != (int *)0x0)) {
        if (piVar2[0xe7] == 1) {
          if (((*(int *)((int)puVar8 + -6) == 2) &&
              (iVar5 = FUN_00900075(piVar2,0,&CActor::RTTI_Type_Descriptor,
                                    &CMonster::RTTI_Type_Descriptor,0), iVar5 != 0)) &&
             (*(int *)((int)puVar8 + -6) == 2)) {
            uVar3 = puVar8[2];
            *(undefined4 *)(iVar5 + 0x3bc) = *puVar8;
            *(undefined4 *)(iVar5 + 0x3c8) = uVar3;
            *(undefined4 *)(iVar5 + 0x430) = 1;
          }
        }
        else {
          iVar5 = piVar2[0x27];
          iVar6 = FUN_00404ba0();
          param_2 = (uint)(iVar5 == *(int *)(iVar6 + 0x5f50));
          if (*(int *)((int)puVar8 + -6) == 1) {
            if (param_2 != 0) {
              uVar1 = *(ushort *)(piVar2 + 0x22);
              iVar5 = FUN_00404ba0();
              if (((uVar1 < 10) &&
                  (iVar5 = (uint)uVar1 * 0x210 + *(int *)(iVar5 + 0x6924),
                  *(int *)(iVar5 + 0x5c) != 0)) && (iVar5 != 0)) {
                *(undefined4 *)(iVar5 + 0x54) = puVar8[1];
                *(undefined4 *)(iVar5 + 0x58) = *puVar8;
                *(undefined4 *)(iVar5 + 0x50) = puVar8[2];
              }
            }
            (**(code **)(*piVar2 + 0x7c))(puVar8[1]);
            (**(code **)(*piVar2 + 0x80))(*puVar8);
            (**(code **)(*piVar2 + 0x78))(puVar8[2]);
          }
          else if ((*(int *)((int)puVar8 + -6) - 2U < 3) &&
                  (iVar5 = FUN_00900075(piVar2,0,&CActor::RTTI_Type_Descriptor,
                                        &CCharacter::RTTI_Type_Descriptor,0), iVar5 != 0)) {
            uVar1 = *(ushort *)(iVar5 + 0x88);
            iVar6 = FUN_00404ba0();
            if ((uVar1 < 10) && (iVar6 = (uint)uVar1 * 0x210 + *(int *)(iVar6 + 0x6924), iVar6 != 0)
               ) {
              iVar4 = *(int *)((int)puVar8 + -6);
              if (iVar4 == 2) {
                if (param_2 != 0) {
                  *(undefined4 *)(iVar6 + 0x40) = *puVar8;
                  *(undefined4 *)(iVar6 + 0x34) = puVar8[2];
                }
                uVar3 = puVar8[2];
                *(undefined4 *)(iVar5 + 0x3bc) = *puVar8;
                *(undefined4 *)(iVar5 + 0x3c8) = uVar3;
              }
              else if (iVar4 == 3) {
                if (param_2 != 0) {
                  *(undefined4 *)(iVar6 + 0x44) = *puVar8;
                  *(undefined4 *)(iVar6 + 0x38) = puVar8[2];
                }
                uVar3 = puVar8[2];
                *(undefined4 *)(iVar5 + 0x3c0) = *puVar8;
                *(undefined4 *)(iVar5 + 0x3cc) = uVar3;
              }
              else if (iVar4 == 4) {
                if (param_2 != 0) {
                  *(undefined4 *)(iVar6 + 0x48) = *puVar8;
                  *(undefined4 *)(iVar6 + 0x3c) = puVar8[2];
                }
                uVar3 = puVar8[2];
                *(undefined4 *)(iVar5 + 0x3c4) = *puVar8;
                *(undefined4 *)(iVar5 + 0x3d0) = uVar3;
              }
            }
          }
        }
      }
      puVar8 = (undefined4 *)((int)puVar8 + 0x12);
      param_1 = param_1 - 1;
    } while (param_1 != 0);
  }
  return 0;
}

