
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    private: class std::ostreambuf_iterator<char,struct std::char_traits<char> > __thiscall
   std::money_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::_Putmfld(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,bool,class
   std::ios_base &,char,bool,class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::_Putmfld
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5,
          int param_6,undefined1 param_7,char param_8,undefined4 ****param_9)

{
  char cVar1;
  bool bVar2;
  undefined1 uVar3;
  locale *plVar4;
  moneypunct<char,1> *pmVar5;
  uint uVar6;
  char ****ppppcVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined1 *puVar11;
  undefined4 ****ppppuVar12;
  uint uVar13;
  uint in_stack_00000030;
  uint in_stack_00000034;
  undefined1 local_f8 [8];
  undefined1 local_f0 [8];
  undefined1 local_e8 [8];
  undefined1 local_e0 [8];
  undefined1 local_d8 [8];
  undefined1 local_d0 [8];
  undefined1 local_c8 [8];
  undefined1 local_c0 [8];
  undefined1 local_b8 [4];
  undefined4 local_b4;
  undefined1 local_b0 [4];
  uint local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  int local_9c;
  uint local_98;
  undefined4 local_94;
  uint local_90;
  moneypunct<char,1> *local_8c;
  undefined4 local_88;
  undefined1 local_84 [28];
  undefined4 ***local_68 [4];
  uint local_58;
  uint local_54;
  char ***local_4c [5];
  uint local_38;
  undefined4 ***local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xe8;
  local_a8 = param_2;
  local_9c = param_6;
  local_94 = CONCAT31(local_94._1_3_,param_7);
  local_8 = 0;
  if (param_5 == '\0') {
    plVar4 = (locale *)FUN_004318d0(local_b8);
    local_8 = CONCAT31(local_8._1_3_,2);
    pmVar5 = (moneypunct<char,1> *)use_facet<std::moneypunct<char,0>_>(plVar4);
  }
  else {
    plVar4 = (locale *)FUN_004318d0(local_b0);
    local_8 = CONCAT31(local_8._1_3_,1);
    pmVar5 = use_facet<std::moneypunct<char,1>_>(plVar4);
  }
  local_8 = local_8 & 0xffffff00;
  local_8c = pmVar5;
  FUN_004327c0();
  grouping(local_4c);
  local_8 = CONCAT31(local_8._1_3_,3);
  uVar6 = (**(code **)(*(int *)pmVar5 + 0x1c))();
  uVar6 = (uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f);
  local_90 = uVar6;
  if (uVar6 < in_stack_00000030) {
    ppppcVar7 = (char ****)local_4c[0];
    if (local_38 < 0x10) {
      ppppcVar7 = local_4c;
    }
    if (*(char *)ppppcVar7 != '\x7f') {
      ppppcVar7 = (char ****)local_4c[0];
      if (local_38 < 0x10) {
        ppppcVar7 = local_4c;
      }
      if ('\0' < *(char *)ppppcVar7) {
        uVar3 = (**(code **)(*(int *)local_8c + 8))();
        local_88 = CONCAT31(local_88._1_3_,uVar3);
        if (local_38 < 0x10) {
          local_4c[0] = (char ***)local_4c;
        }
        uVar6 = in_stack_00000030 - uVar6;
        ppppcVar7 = (char ****)local_4c[0];
        while (((cVar1 = *(char *)ppppcVar7, cVar1 != '\x7f' && ('\0' < cVar1)) &&
               ((uint)(int)cVar1 < uVar6))) {
          uVar6 = uVar6 - (int)cVar1;
          FUN_004329c0(uVar6,1,local_88);
          if ('\0' < *(char *)((int)ppppcVar7 + 1)) {
            ppppcVar7 = (char ****)((int)ppppcVar7 + 1);
          }
        }
      }
    }
  }
  else {
    FUN_004329c0(0,(uVar6 - in_stack_00000030) + 1,0x30);
  }
  local_20 = 0;
  local_1c = 0xf;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
  local_8._0_1_ = 4;
  if (param_8 == '\0') {
    (**(code **)(*(int *)local_8c + 0x20))(&local_88);
    uVar8 = positive_sign(local_84);
    local_8._0_1_ = 6;
  }
  else {
    (**(code **)(*(int *)local_8c + 0x24))();
    uVar8 = negative_sign(local_84);
    local_8._0_1_ = 5;
  }
  FUN_00402bb0(uVar8);
  FUN_00402f30(1,0);
  local_58 = 0;
  local_54 = 0xf;
  local_68[0] = (undefined4 ***)((uint)local_68[0] & 0xffffff00);
  local_8._0_1_ = 7;
  if ((*(uint *)(local_9c + 0x14) & 8) != 0) {
    uVar8 = curr_symbol(local_84);
    local_8._0_1_ = 8;
    FUN_00402bb0(uVar8);
    local_8._0_1_ = 7;
    FUN_00402f30(1,0);
  }
  bVar2 = false;
  uVar13 = 0;
  uVar6 = 0;
  do {
    cVar1 = local_84[uVar6 - 4];
    if (cVar1 == ' ') {
      uVar13 = uVar13 + 1;
LAB_0089020c:
      if (uVar6 != 3) {
        bVar2 = true;
      }
    }
    else if (cVar1 == '$') {
      uVar13 = uVar13 + local_58;
    }
    else if (cVar1 == '+') {
      uVar13 = uVar13 + local_20;
    }
    else if (cVar1 == 'v') {
      if (local_90 < in_stack_00000030) {
        iVar9 = 0;
      }
      else {
        iVar9 = (local_90 - in_stack_00000030) + 1;
      }
      uVar13 = uVar13 + (local_90 != 0) + in_stack_00000030 + iVar9;
    }
    else if (cVar1 == 'x') goto LAB_0089020c;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 4);
  uVar6 = *(uint *)(local_9c + 0x20);
  if (((*(int *)(local_9c + 0x24) < 0) || ((*(int *)(local_9c + 0x24) < 1 && (uVar6 == 0)))) ||
     (uVar6 <= uVar13)) {
    iVar9 = 0;
  }
  else {
    iVar9 = uVar6 - uVar13;
  }
  local_ac = *(uint *)(local_9c + 0x14) & 0x1c0;
  if ((local_ac != 0x40) && ((local_ac != 0x100 || (!bVar2)))) {
    puVar10 = (undefined4 *)_Rep(&local_a4,param_3,param_4,local_94,iVar9);
    param_3 = *puVar10;
    param_4 = puVar10[1];
    iVar9 = 0;
  }
  pmVar5 = local_8c;
  local_98 = 0;
  do {
    cVar1 = local_84[local_98 - 4];
    if (cVar1 == ' ') {
      local_a4 = param_3;
      local_a0 = param_4;
      FUN_006efb60(local_94);
      param_3 = local_a4;
      param_4 = local_a0;
LAB_00890466:
      if (local_ac != 0x100) goto LAB_0089049b;
      puVar10 = (undefined4 *)_Rep(local_c0,param_3,param_4,local_94,iVar9);
      iVar9 = 0;
LAB_00890490:
      param_3 = *puVar10;
      param_4 = puVar10[1];
    }
    else {
      if (cVar1 == '$') {
        ppppuVar12 = (undefined4 ****)local_68[0];
        if (local_54 < 0x10) {
          ppppuVar12 = local_68;
        }
        puVar11 = local_f0;
        uVar6 = local_58;
LAB_008902f4:
        puVar10 = (undefined4 *)_Put(puVar11,param_3,param_4,ppppuVar12,uVar6);
        goto LAB_00890490;
      }
      if (cVar1 == '+') {
        if (local_20 != 0) {
          ppppuVar12 = (undefined4 ****)local_30[0];
          if (local_1c < 0x10) {
            ppppuVar12 = local_30;
          }
          uVar6 = 1;
          puVar11 = local_c8;
          goto LAB_008902f4;
        }
      }
      else {
        if (cVar1 == 'v') {
          if (local_90 == 0) {
            ppppuVar12 = param_9;
            if (in_stack_00000034 < 0x10) {
              ppppuVar12 = &param_9;
            }
            puVar11 = local_f8;
            uVar6 = in_stack_00000030;
          }
          else if (local_90 < in_stack_00000030) {
            ppppuVar12 = param_9;
            if (in_stack_00000034 < 0x10) {
              ppppuVar12 = &param_9;
            }
            puVar10 = (undefined4 *)
                      _Put(local_d8,param_3,param_4,ppppuVar12,in_stack_00000030 - local_90);
            param_3 = *puVar10;
            param_4 = puVar10[1];
            uVar3 = (**(code **)(*(int *)pmVar5 + 4))();
            local_b4 = CONCAT31(local_b4._1_3_,uVar3);
            FUN_006efb60(local_b4);
            ppppuVar12 = param_9;
            if (in_stack_00000034 < 0x10) {
              ppppuVar12 = &param_9;
            }
            ppppuVar12 = (undefined4 ****)((in_stack_00000030 - local_90) + (int)ppppuVar12);
            puVar11 = local_e8;
            uVar6 = local_90;
          }
          else {
            FUN_006efb60(0x30);
            uVar3 = (**(code **)(*(int *)pmVar5 + 4))();
            local_8c = (moneypunct<char,1> *)CONCAT31(local_8c._1_3_,uVar3);
            FUN_006efb60(local_8c);
            puVar10 = (undefined4 *)_Rep(local_e0,param_3,param_4,0x30,local_90 - in_stack_00000030)
            ;
            ppppuVar12 = param_9;
            if (in_stack_00000034 < 0x10) {
              ppppuVar12 = &param_9;
            }
            param_4 = puVar10[1];
            param_3 = *puVar10;
            puVar11 = local_d0;
            uVar6 = in_stack_00000030;
          }
          goto LAB_008902f4;
        }
        if (cVar1 == 'x') goto LAB_00890466;
      }
    }
LAB_0089049b:
    local_98 = local_98 + 1;
    if (3 < local_98) {
      if (1 < local_20) {
        ppppuVar12 = (undefined4 ****)local_30[0];
        if (local_1c < 0x10) {
          ppppuVar12 = local_30;
        }
        puVar10 = (undefined4 *)_Put(local_c0,param_3,param_4,(int)ppppuVar12 + 1,local_20 - 1);
        param_3 = *puVar10;
        param_4 = puVar10[1];
      }
      *(undefined4 *)(local_9c + 0x20) = 0;
      *(undefined4 *)(local_9c + 0x24) = 0;
      _Rep(local_a8,param_3,param_4,local_94,iVar9);
      FUN_00402f30(1,0);
      FUN_00402f30(1,0);
      FUN_00402f30(1,0);
      FUN_00402f30(1,0);
      FUN_0089dbbc();
      return;
    }
  } while( true );
}

