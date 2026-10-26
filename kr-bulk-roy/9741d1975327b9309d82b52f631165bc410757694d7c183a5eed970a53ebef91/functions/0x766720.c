
/* WARNING: Type propagation algorithm not settling */

void FUN_00766720(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  uint uVar7;
  int unaff_EBX;
  undefined4 *puVar8;
  uint uVar9;
  int unaff_ESI;
  int unaff_EDI;
  int *piVar10;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  uint local_d4;
  uint local_d0;
  undefined1 auStack_cc [4];
  int local_c8;
  int *local_c4;
  int local_c0 [3];
  uint local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  undefined1 auStack_a0 [88];
  undefined4 uStack_48;
  undefined4 uStack_2c;
  int *piStack_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0090ece3;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_e4;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff10;
  ExceptionList = &local_14;
  FUN_00744640(param_1,param_2);
  local_a4 = *(int *)(*(int *)(in_ECX + 0x24) + 0x1c);
  if ((local_a4 != 0) && (*(int *)(in_ECX + 0xf4) != 0)) {
    local_a8 = *(int *)(*(int *)(in_ECX + 0xf4) + 0x10);
    local_c0[2] = FUN_008fed10(uVar3);
    local_e0 = 0;
    if (0 < *(int *)(in_ECX + 0x138)) {
      local_e4 = 0;
      do {
        local_d0 = *(int *)(in_ECX + 0x134) + local_e0;
        if ((uint)(*(int *)(in_ECX + 0x114) - *(int *)(in_ECX + 0x110) >> 2) <= local_d0) break;
        local_c8 = *(int *)(in_ECX + 0xa8) + local_e4;
        iVar5 = *(int *)(in_ECX + 0xa4);
        iVar6 = *(int *)(in_ECX + 0xac);
        local_c0[0] = local_c0[2] + local_c8;
        if (*(char *)(in_ECX + 0x120) != '\0') {
          iVar5 = iVar5 + 0xf;
          iVar6 = iVar6 + -0xf;
        }
        if (*(int *)(in_ECX + 0xb0) < local_c0[0]) {
          local_c0[0] = *(int *)(in_ECX + 0xb0);
        }
        local_c0[0] = local_c0[0] + param_2;
        local_c8 = local_c8 + param_2;
        iVar1 = *(int *)(*(int *)(in_ECX + 0x110) + local_d0 * 4);
        iVar2 = *(int *)(iVar1 + 0x10);
        if (iVar2 != 0) {
          FUN_007586b0(iVar1,0,iVar2,0,*(undefined4 *)(in_ECX + 0xf8),
                       *(undefined4 *)(in_ECX + 0x100),iVar5 + param_1,local_c8,iVar6 + param_1,
                       local_c0[0]);
        }
        local_e4 = local_e4 + local_c0[2];
        local_e0 = local_e0 + 1;
      } while (local_e0 < *(int *)(in_ECX + 0x138));
    }
    if (*(char *)(in_ECX + 0x148) != '\0') {
      uVar3 = *(uint *)(in_ECX + 0x14c);
      local_d4 = *(uint *)(in_ECX + 0x150);
      if ((int)local_d4 < (int)uVar3) {
        iVar5 = *(int *)(in_ECX + 0x158);
        local_e4 = *(int *)(in_ECX + 0x154);
        uVar9 = local_d4;
        local_d4 = uVar3;
      }
      else {
        iVar5 = *(int *)(in_ECX + 0x154);
        local_e4 = *(int *)(in_ECX + 0x158);
        uVar9 = uVar3;
      }
      uVar7 = local_e4 - iVar5 >> 0x1f;
      uVar3 = local_e4 - iVar5 ^ uVar7;
      iVar6 = local_d4 - uVar9;
      local_b4 = uVar9;
      local_b0 = iVar5;
      if ((0 < iVar6) || ((iVar6 == 0 && (uVar3 != uVar7 && -1 < (int)(uVar3 - uVar7))))) {
        iVar6 = iVar6 + 1;
        local_ac = 0;
        local_a8 = iVar6;
        if (0 < iVar6) {
          do {
            local_d0 = uVar9;
            if (*(int *)(in_ECX + 0x134) <= (int)uVar9) {
              iVar6 = *(int *)(in_ECX + 0x110);
              if (((uint)(*(int *)(in_ECX + 0x114) - iVar6 >> 2) <= uVar9) ||
                 (*(int *)(in_ECX + 0x138) + *(int *)(in_ECX + 0x134) <= (int)uVar9)) break;
              local_d8 = local_e4;
              if (uVar9 == local_b4) {
                local_dc = iVar5;
                if (uVar9 == local_d4) {
                  if ((local_e4 <= iVar5) && (local_dc = local_e4, local_e4 < iVar5)) {
                    local_d8 = iVar5;
                  }
                }
                else {
                  local_d8 = *(int *)(*(int *)(iVar6 + uVar9 * 4) + 0x10);
                }
              }
              else {
                local_dc = 0;
                if (uVar9 != local_d4) {
                  local_d8 = *(int *)(*(int *)(iVar6 + uVar9 * 4) + 0x10);
                }
              }
              local_c4 = *(int **)(in_ECX + 0xac);
              local_c8 = *(int *)(in_ECX + 0xa8);
              iVar5 = *(int *)(in_ECX + 0xa4);
              local_e0 = 0;
              local_c0[1] = 0;
              piVar4 = *(int **)(iVar6 + uVar9 * 4);
              local_c0[0] = *(int *)(in_ECX + 0xb0);
              if (7 < (uint)piVar4[5]) {
                piVar4 = (int *)*piVar4;
              }
              piVar10 = local_c0 + 1;
              (**(code **)(**(int **)(in_ECX + 0xf4) + 0x30))(&local_e0,piVar10,piVar4,local_dc);
              iVar5 = iVar5 + unaff_EDI;
              puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x110) + uVar9 * 4);
              local_d8 = local_d8 + (uVar9 - *(int *)(in_ECX + 0x134)) * local_c8;
              if (7 < (uint)puVar8[5]) {
                puVar8 = (undefined4 *)*puVar8;
              }
              (**(code **)(**(int **)(in_ECX + 0xf4) + 0x30))
                        (&stack0xffffff10,auStack_cc,(int)puVar8 + unaff_ESI * 2,
                         unaff_EBX - unaff_ESI);
              iVar6 = unaff_EBX + local_dc;
              if (*(int *)(in_ECX + 0xb0) <= unaff_EBX + local_dc) {
                iVar6 = *(int *)(in_ECX + 0xb0);
              }
              local_e4 = (int)piVar10 + param_1 + iVar5;
              unaff_EBX = unaff_EBX + param_2;
              _eh_vector_constructor_iterator_
                        (local_c0,0x14,6,(_func_void_void_ptr *)&LAB_0074d950,FUN_005f5d10);
              uStack_48 = 0;
              uStack_2c = 0;
              FUN_0077bc10(iVar5 + param_1,unaff_EBX,local_e4,iVar6 + param_2);
              piVar4 = local_c4;
              (**(code **)(*local_c4 + 0x164))(local_c4,0x44);
              (**(code **)(*piVar4 + 0x104))(piVar4,0,0);
              (**(code **)(*piVar4 + 0x14c))(piVar4,4,2,&local_d4,0x14);
              uStack_c = 1;
              if (piStack_28 != (int *)0x0) {
                (**(code **)(*piStack_28 + 8))(piStack_28);
                piStack_28 = (int *)0x0;
              }
              uStack_c = 0xffffffff;
              _eh_vector_destructor_iterator_(auStack_a0,0x14,6,FUN_005f5d10);
              iVar6 = local_a8;
              iVar5 = local_b0;
            }
            local_ac = local_ac + 1;
            uVar9 = local_d0 + 1;
            local_d0 = uVar9;
          } while (local_ac < iVar6);
        }
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_e4);
  return;
}

