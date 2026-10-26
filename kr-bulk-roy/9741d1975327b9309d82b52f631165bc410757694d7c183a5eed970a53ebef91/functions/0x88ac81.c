
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    private: class std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   __thiscall std::money_put<unsigned short,class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > >::_Putmfld(class std::ostreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> >,bool,class std::ios_base &,unsigned
   short,bool,class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> >)const 
    private: class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > __thiscall
   std::money_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   >::_Putmfld(class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >,bool,class
   std::ios_base &,wchar_t,bool,class std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >)const 
   
   Library: Visual Studio 2010 Release */

void Putmfld(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4,int param_5,
            ushort param_6,char param_7,undefined4 *param_8)

{
  char cVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  char ****ppppcVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  int in_ECX;
  uint uVar13;
  uint in_stack_00000030;
  uint in_stack_00000034;
  undefined1 local_f0 [8];
  undefined1 local_e8 [8];
  undefined1 local_e0 [8];
  undefined1 local_d8 [8];
  undefined1 local_d0 [8];
  undefined1 local_c8 [8];
  undefined1 local_c0 [8];
  undefined1 local_b8 [8];
  undefined1 local_b0 [4];
  undefined1 local_ac [4];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  uint local_9c;
  uint local_98;
  int local_94;
  uint local_90;
  int *local_8c;
  char local_88 [4];
  undefined1 local_84 [28];
  undefined4 local_68;
  uint local_58;
  uint local_54;
  char ***local_4c [5];
  uint local_38;
  undefined4 local_30;
  uint local_20;
  uint local_1c;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xe0;
  local_a8 = param_1;
  local_98 = (uint)param_6;
  local_94 = param_5;
  local_8 = 0;
  if (param_4 == '\0') {
    uVar4 = FUN_004318d0(local_b0);
    local_8 = CONCAT31(local_8._1_3_,2);
    piVar5 = (int *)use_facet<>(uVar4);
  }
  else {
    uVar4 = FUN_004318d0(local_ac);
    local_8 = CONCAT31(local_8._1_3_,1);
    piVar5 = (int *)use_facet<>(uVar4);
  }
  local_8 = local_8 & 0xffffff00;
  local_8c = piVar5;
  FUN_004327c0();
  uVar6 = FUN_004303a0(0x30,0,in_ECX + 8);
  local_9c = uVar6 & 0xffff;
  grouping(local_4c);
  local_8 = CONCAT31(local_8._1_3_,3);
  uVar7 = (**(code **)(*piVar5 + 0x1c))();
  local_90 = (uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f);
  if (local_90 < in_stack_00000030) {
    ppppcVar8 = (char ****)local_4c[0];
    if (local_38 < 0x10) {
      ppppcVar8 = local_4c;
    }
    if (*(char *)ppppcVar8 != '\x7f') {
      ppppcVar8 = (char ****)local_4c[0];
      if (local_38 < 0x10) {
        ppppcVar8 = local_4c;
      }
      if ('\0' < *(char *)ppppcVar8) {
        uVar3 = (**(code **)(*local_8c + 8))();
        if (local_38 < 0x10) {
          local_4c[0] = (char ***)local_4c;
        }
        uVar6 = in_stack_00000030 - local_90;
        ppppcVar8 = (char ****)local_4c[0];
        while( true ) {
          cVar1 = *(char *)ppppcVar8;
          if (((cVar1 == '\x7f') || (cVar1 < '\x01')) || (uVar6 <= (uint)(int)cVar1)) break;
          uVar6 = uVar6 - (int)cVar1;
          FUN_004f0b60(uVar6,1,uVar3);
          if ('\0' < *(char *)((int)ppppcVar8 + 1)) {
            ppppcVar8 = (char ****)((int)ppppcVar8 + 1);
          }
        }
      }
    }
  }
  else {
    FUN_004f0b60(0,(local_90 - in_stack_00000030) + 1,uVar6 & 0xffff);
  }
  local_20 = 0;
  local_1c = 7;
  local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
  local_8._0_1_ = 4;
  if (param_7 == '\0') {
    (**(code **)(*local_8c + 0x20))(local_88);
    uVar4 = positive_sign(local_84);
    local_8._0_1_ = 6;
  }
  else {
    (**(code **)(*local_8c + 0x24))();
    uVar4 = negative_sign(local_84);
    local_8._0_1_ = 5;
  }
  FUN_00402800(uVar4);
  FUN_00402a00(1,0);
  local_58 = 0;
  local_54 = 7;
  local_68 = (undefined4 *)((uint)local_68._2_2_ << 0x10);
  local_8._0_1_ = 7;
  if ((*(uint *)(local_94 + 0x14) & 8) != 0) {
    uVar4 = curr_symbol(local_84);
    local_8._0_1_ = 8;
    FUN_00402800(uVar4);
    local_8._0_1_ = 7;
    FUN_00402a00(1,0);
  }
  uVar6 = local_90;
  bVar2 = false;
  uVar13 = 0;
  uVar7 = 0;
  do {
    cVar1 = local_88[uVar7];
    if (cVar1 == ' ') {
      uVar13 = uVar13 + 1;
LAB_0088aeed:
      if (uVar7 != 3) {
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
    else if (cVar1 == 'x') goto LAB_0088aeed;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 4);
  uVar7 = *(uint *)(local_94 + 0x20);
  if (((*(int *)(local_94 + 0x24) < 0) || ((*(int *)(local_94 + 0x24) < 1 && (uVar7 == 0)))) ||
     (uVar7 <= uVar13)) {
    iVar9 = 0;
  }
  else {
    iVar9 = uVar7 - uVar13;
  }
  local_90 = *(uint *)(local_94 + 0x14) & 0x1c0;
  if ((local_90 != 0x40) && ((local_90 != 0x100 || (!bVar2)))) {
    puVar10 = (undefined4 *)Rep(&local_a4,param_2,param_3,local_98,iVar9);
    param_2 = *puVar10;
    param_3 = puVar10[1];
    iVar9 = 0;
  }
  uVar7 = 0;
  do {
    cVar1 = local_88[uVar7];
    if (cVar1 == ' ') {
      local_a4 = param_2;
      local_a0 = param_3;
      FUN_00430900(local_98);
      param_2 = local_a4;
      param_3 = local_a0;
LAB_0088b11e:
      if (local_90 != 0x100) goto LAB_0088b153;
      puVar10 = (undefined4 *)Rep(local_b8,param_2,param_3,local_98,iVar9);
      iVar9 = 0;
LAB_0088b148:
      param_2 = *puVar10;
      param_3 = puVar10[1];
    }
    else {
      if (cVar1 == '$') {
        puVar10 = local_68;
        if (local_54 < 8) {
          puVar10 = &local_68;
        }
        puVar11 = local_e8;
        uVar13 = local_58;
LAB_0088afbb:
        puVar10 = (undefined4 *)Put(puVar11,param_2,param_3,puVar10,uVar13);
        goto LAB_0088b148;
      }
      if (cVar1 == '+') {
        if (local_20 != 0) {
          puVar10 = local_30;
          if (local_1c < 8) {
            puVar10 = &local_30;
          }
          uVar13 = 1;
          puVar11 = local_f0;
          goto LAB_0088afbb;
        }
      }
      else {
        if (cVar1 == 'v') {
          if (uVar6 == 0) {
            puVar10 = param_8;
            if (in_stack_00000034 < 8) {
              puVar10 = &param_8;
            }
            puVar11 = local_c0;
            uVar13 = in_stack_00000030;
          }
          else if (uVar6 < in_stack_00000030) {
            puVar10 = param_8;
            if (in_stack_00000034 < 8) {
              puVar10 = &param_8;
            }
            puVar10 = (undefined4 *)Put(local_d0,param_2,param_3,puVar10,in_stack_00000030 - uVar6);
            param_2 = *puVar10;
            param_3 = puVar10[1];
            uVar3 = (**(code **)(*local_8c + 4))();
            FUN_00430900(uVar3);
            puVar10 = param_8;
            if (in_stack_00000034 < 8) {
              puVar10 = &param_8;
            }
            puVar10 = (undefined4 *)((int)puVar10 + (in_stack_00000030 - uVar6) * 2);
            puVar11 = local_e0;
            uVar13 = uVar6;
          }
          else {
            FUN_00430900(local_9c);
            uVar3 = (**(code **)(*local_8c + 4))();
            FUN_00430900(uVar3);
            puVar12 = (undefined4 *)Rep(local_d8,param_2,param_3,local_9c,uVar6 - in_stack_00000030)
            ;
            puVar10 = param_8;
            if (in_stack_00000034 < 8) {
              puVar10 = &param_8;
            }
            param_3 = puVar12[1];
            param_2 = *puVar12;
            puVar11 = local_c8;
            uVar13 = in_stack_00000030;
          }
          goto LAB_0088afbb;
        }
        if (cVar1 == 'x') goto LAB_0088b11e;
      }
    }
LAB_0088b153:
    uVar7 = uVar7 + 1;
    if (3 < uVar7) {
      if (1 < local_20) {
        puVar10 = local_30;
        if (local_1c < 8) {
          puVar10 = &local_30;
        }
        puVar10 = (undefined4 *)Put(local_b8,param_2,param_3,(int)puVar10 + 2,local_20 - 1);
        param_2 = *puVar10;
        param_3 = puVar10[1];
      }
      *(undefined4 *)(local_94 + 0x20) = 0;
      *(undefined4 *)(local_94 + 0x24) = 0;
      Rep(local_a8,param_2,param_3,local_98,iVar9);
      FUN_00402a00(1,0);
      FUN_00402a00(1,0);
      FUN_00402f30(1,0);
      FUN_00402a00(1,0);
      FUN_0089dbbc();
      return;
    }
  } while( true );
}

