
void FUN_00481320(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined2 local_70 [8];
  undefined4 local_60;
  undefined4 local_5c;
  undefined *puStack_58;
  undefined ***pppuStack_54;
  uint local_38;
  int local_30;
  char *local_2c;
  undefined1 *local_28;
  undefined **local_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00944f81;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x134) != 0) {
    *(undefined1 *)(in_ECX + 0x14c) = 1;
    local_38 = 0;
    if (*(int *)(in_ECX + 0x140) - *(int *)(in_ECX + 0x13c) >> 2 != 0) {
      do {
        if ((DAT_00f8d9a8 & 1) == 0) {
          DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
          local_c = 0;
          DAT_00f8d9b4 = 0;
          pppuStack_54 = (undefined ***)0x4813ad;
          iVar1 = FUN_00891268();
          if (iVar1 == 0) {
            local_2c = (char *)0x0;
            pppuStack_54 = (undefined ***)0x48162b;
            std::exception::exception((exception *)local_24,&local_2c);
            pppuStack_54 = local_24;
            local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            puStack_58 = &UNK_00481642;
            __CxxThrowException_8();
          }
          DAT_00f8d9b0 = iVar1;
          *(int *)iVar1 = iVar1;
          *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
          *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
          *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
          *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
          local_c = CONCAT31(local_c._1_3_,1);
          pppuStack_54 = (undefined ***)0x4813f1;
          FUN_00521080();
          pppuStack_54 = (undefined ***)0x4813fb;
          _atexit((_func_4879 *)&LAB_00bccc50);
          local_c = 0xffffffff;
        }
        pppuStack_54 = (undefined ***)0x481420;
        FUN_008438c0();
        if (local_30 != DAT_00f8d9b0) {
          iVar1 = *(int *)(local_30 + 0x10);
          if (iVar1 != 0) {
            if (*(int *)(*(int *)(in_ECX + 0x100) + 0xcc) == 0) {
              iVar2 = 0;
            }
            else {
              pppuStack_54 = (undefined ***)0x48145b;
              iVar2 = FUN_00412c70();
            }
            if ((DAT_00f94390 & 1) == 0) {
              DAT_00f94390 = DAT_00f94390 | 1;
              local_c = 2;
              FUN_004e1590();
              pppuStack_54 = (undefined ***)0x481488;
              _atexit((_func_4879 *)&LAB_00bccc80);
              local_c = 0xffffffff;
            }
            iVar3 = 0;
            if (DAT_00f94300 != -0x16f8) {
              pppuStack_54 = (undefined ***)0x4814ab;
              iVar3 = FUN_00508e40();
            }
            local_28 = (undefined1 *)local_70;
            local_5c = 7;
            local_60 = 0;
            local_70[0] = 0;
            pppuStack_54 = (undefined ***)iVar3;
            FUN_004026e0(iVar1 + 0x98,0,0xffffffff);
            FUN_00482950();
            if (iVar3 < (int)(uint)*(byte *)(local_38 * 4 + 2 + *(int *)(in_ECX + 0x13c))) {
              *(undefined4 *)(*(int *)(iVar2 + 0x24c) + 0x154) = 0xffff0000;
              (**(code **)(**(int **)(iVar2 + 0x24c) + 200))();
              *(undefined4 *)(*(int *)(iVar2 + 0x250) + 0x154) = 0xffff0000;
              (**(code **)(**(int **)(iVar2 + 0x250) + 200))();
              *(undefined1 *)(in_ECX + 0x14c) = 0;
            }
          }
        }
        local_38 = local_38 + 1;
      } while (local_38 < (uint)(*(int *)(in_ECX + 0x140) - *(int *)(in_ECX + 0x13c) >> 2));
    }
    pppuStack_54 = (undefined ***)0x481593;
    FUN_00749920();
    (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
    pppuStack_54 = (undefined ***)0x4815b5;
    (**(code **)(**(int **)(in_ECX + 0x10c) + 0x94))();
    pppuStack_54 = (undefined ***)0x0;
    puStack_58 = (undefined *)0x4815cc;
    FUN_007597b0();
    pppuStack_54 = (undefined ***)0x4815dc;
    (**(code **)(**(int **)(in_ECX + 0x10c) + 200))();
    pppuStack_54 = (undefined ***)0x0;
    puStack_58 = (undefined *)0x4815f4;
    FUN_007597b0();
    pppuStack_54 = (undefined ***)0x481606;
    (**(code **)(**(int **)(in_ECX + 0x110) + 200))();
  }
  ExceptionList = local_14;
  return;
}

