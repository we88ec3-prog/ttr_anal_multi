
void FUN_00603430(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int *in_ECX;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_44;
  int iStack_40;
  int iStack_3c;
  uint uStack_38;
  uint uStack_34;
  int iStack_30;
  int *local_2c;
  char *pcStack_28;
  undefined **appuStack_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00946d5d;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_44 = 0;
  local_2c = in_ECX;
  iVar2 = (**(code **)(*in_ECX + 0x198))(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
  if (iVar2 < 1) {
    ExceptionList = local_14;
    return;
  }
  do {
    iVar2 = *(int *)(in_ECX[0x3d] + local_44 * 4);
    if ((DAT_00f8d9a8 & 1) == 0) {
      DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
      uStack_c = 0;
      DAT_00f8d9b4 = 0;
      iVar3 = FUN_00891268(0x18);
      if (iVar3 == 0) {
        pcStack_28 = (char *)0x0;
        std::exception::exception((exception *)appuStack_24,&pcStack_28);
        appuStack_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(appuStack_24,&DAT_00c857a8);
      }
      DAT_00f8d9b0 = iVar3;
      *(int *)iVar3 = iVar3;
      *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
      *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
      *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
      *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
      uStack_c = CONCAT31(uStack_c._1_3_,1);
      FUN_00521080(&DAT_00f8d9bc);
      _atexit((_func_4879 *)&LAB_00bccc50);
      uStack_c = 0xffffffff;
    }
    iStack_40 = *(int *)(iVar2 + 0x250);
    FUN_008438c0(&iStack_40);
    if ((iStack_3c != DAT_00f8d9b0) && (*(int *)(iStack_3c + 0x10) != 0)) {
      if (*(int *)(iVar2 + 0x2b4) < 1) {
        if ((DAT_00fb744c & 1) == 0) {
          DAT_00fb744c = DAT_00fb744c | 1;
          uStack_c = 3;
          FUN_004eec60();
          _atexit(FUN_00bcd140);
          uStack_c = 0xffffffff;
        }
        puVar4 = (ushort *)FUN_004eeb00();
        if (puVar4 == (ushort *)0x0) {
          iVar3 = 0;
        }
        else {
          if ((DAT_00f94394 & 1) == 0) {
            DAT_00f94394 = DAT_00f94394 | 1;
            uStack_c = 4;
            FUN_005c3de0();
            _atexit((_func_4879 *)&LAB_00bccc30);
            uStack_c = 0xffffffff;
          }
          uStack_34 = (uint)puVar4[1];
          uVar6 = (uint)*puVar4;
          iStack_40 = (int)((ulonglong)uStack_34 % (ulonglong)(longlong)(int)uVar6);
          uStack_38 = uVar6;
          iVar3 = FUN_008fed10();
          iVar3 = *(int *)(&DAT_00f94448 + iVar3 * -4);
          if (uStack_34 - 1 == uVar6) {
            *(undefined4 *)(iVar2 + 0x2b4) = 0x3c;
          }
        }
      }
      else {
        if ((DAT_00f94394 & 1) == 0) {
          DAT_00f94394 = DAT_00f94394 | 1;
          uStack_c = 2;
          FUN_005c3de0();
          _atexit((_func_4879 *)&LAB_00bccc30);
          uStack_c = 0xffffffff;
        }
        iVar5 = *(int *)(iVar2 + 0x2b4);
        iStack_40 = (0x3c - iVar5) % 0x3c;
        iVar3 = FUN_008fed10();
        iVar3 = *(int *)(&DAT_00f944b0 + iVar3 * -4);
        *(int *)(iVar2 + 0x2b4) = iVar5 + -1;
      }
      if (iVar3 != *(int *)(iVar2 + 0x2b8)) {
        iVar5 = *(int *)(iVar2 + 0x2ac);
        if (((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) &&
           (iVar5 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
          FUN_0077b200();
        }
        (**(code **)(**(int **)(iVar2 + 0x2ac) + 200))();
        *(int *)(iVar2 + 0x2b8) = iVar3;
      }
      if ((*(int *)(iVar2 + 600) == 0) ||
         (uVar6 = *(uint *)(*(int *)(iVar2 + 0x2a8) + 0x28), iVar3 = FUN_0051c080(),
         ((uVar6 & 0x100) != 0) != (iVar3 != 0))) {
        iVar3 = *(int *)(iVar2 + 600);
        if ((iVar3 != 0) && ((*(int *)(iVar3 + 0x68) != 0 && (*(int *)(iVar3 + 0x68) != 0)))) {
          uVar1 = *(ushort *)(*(int *)(iVar3 + 0x68) + 8);
          iVar3 = FUN_00404ba0();
          iVar3 = *(int *)(iVar3 + 0x6928);
          uStack_34 = (uint)uVar1;
          FUN_004a4cc0(&uStack_34);
          if ((iStack_30 == *(int *)(iVar3 + 0x14)) ||
             ((*(int *)(iStack_30 + 0x10) == 0 || (*(int *)(*(int *)(iStack_30 + 0x10) + 0xc) == 0))
             )) {
            uVar8 = *(undefined4 *)(iVar2 + 0x24c);
            uVar7 = *(undefined4 *)(iVar2 + 0x248);
            goto LAB_006037a1;
          }
        }
      }
      else {
        uVar8 = *(undefined4 *)(iVar2 + 0x24c);
        uVar7 = *(undefined4 *)(iVar2 + 0x248);
LAB_006037a1:
        FUN_005dd050(uVar7,uVar8);
      }
    }
    in_ECX = local_2c;
    local_44 = local_44 + 1;
    iVar2 = (**(code **)(*local_2c + 0x198))();
    if (iVar2 <= local_44) {
      ExceptionList = local_14;
      return;
    }
  } while( true );
}

