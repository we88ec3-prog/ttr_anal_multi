
/* WARNING: Removing unreachable block (ram,0x0048f598) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0048ee70(int *param_1)

{
  uint uVar1;
  void **ppvVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  DWORD DVar7;
  int iVar8;
  undefined4 uStack_2c;
  int iStack_28;
  int iStack_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00949a20;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  iVar4 = *(int *)(param_1[0x2fd5] + 0x20);
  ppvVar2 = &local_14;
  local_14 = ExceptionList;
  while (ExceptionList = ppvVar2, iVar4 == 0) {
    Sleep(3);
    ppvVar2 = ExceptionList;
    iVar4 = *(int *)(param_1[0x2fd5] + 0x20);
  }
  uVar1 = DAT_00fdf6f4 & 1;
  param_1[0xd] = 0;
  if (uVar1 == 0) {
    DAT_00fdf6f4 = DAT_00fdf6f4 | 1;
    local_c = 0;
    FUN_0049b490(uVar3);
    local_c = 0xffffffff;
  }
  FUN_0049b5f0();
  D3DXCreateSprite(param_1[4],param_1 + 0x2fd4);
  FUN_0048e9a0();
  iVar4 = FUN_006dfca0();
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  DAT_00fb7984 = *(undefined4 *)(iVar4 + 0xc4);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 2;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  DAT_00fb7988 = *(undefined4 *)(iVar4 + 0xcc);
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_c = 3;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    local_c = 0xffffffff;
  }
  FUN_00736910();
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_c = 4;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_c = 0xffffffff;
  }
  FUN_00735760();
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 5;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_00589d30();
  if ((DAT_00fc18fc & 1) == 0) {
    DAT_00fc18fc = DAT_00fc18fc | 1;
    local_c = 6;
    FUN_005548f0();
    _atexit((_func_4879 *)&LAB_00bcdcd0);
    local_c = 0xffffffff;
  }
  FUN_00555770();
  if ((DAT_00fc1a34 & 1) == 0) {
    DAT_00fc1a34 = DAT_00fc1a34 | 1;
    local_c = 7;
    FUN_00737210();
    _atexit(FUN_00bce000);
    local_c = 0xffffffff;
  }
  FUN_00737550(&DAT_00fc1a38);
  param_1[0x2ff3] = 1;
  FUN_007aad40(param_1[4]);
  if (param_1[0x2ff4] == 0) {
    if ((DAT_00fc18fc & 1) == 0) {
      DAT_00fc18fc = DAT_00fc18fc | 1;
      local_c = 8;
      FUN_005548f0();
      _atexit((_func_4879 *)&LAB_00bcdcd0);
      local_c = 0xffffffff;
    }
    FUN_00402a70("nodafile",8);
    FUN_00402a70("nodafile",8);
    if (DAT_00fc1908 != 0) {
      uStack_2c = 0;
      piVar5 = (int *)FUN_00555a00(&DAT_00fc1900);
      iVar8 = piVar5[1] - *piVar5;
      iVar4 = iVar8 >> 0x1f;
      if (iVar8 / 0x1c + iVar4 != iVar4) {
        FUN_00403040(*piVar5,0,0xffffffff);
        if ((DAT_00fe1e44 & 1) == 0) {
          DAT_00fe1e44 = DAT_00fe1e44 | 1;
          local_c = 9;
          FUN_00531b40();
          _atexit(thunk_FUN_00531c60);
          local_c = 0xffffffff;
        }
        FUN_00555af0(&iStack_28,&DAT_00fe1e48);
        local_c = 10;
        if (iStack_28 != iStack_24) {
          uVar3 = FUN_0089289d();
          FUN_00403040(iStack_28 + (uVar3 % (uint)((iStack_24 - iStack_28) / 0x1c)) * 0x1c,0,
                       0xffffffff);
        }
        FUN_00402a70("UI\\Texture\\Tooltip\\textTooltipTexture.dds",0x29);
        if (DAT_00fc1984 != 0) {
          FUN_005558c0();
          FUN_00555770();
        }
        iVar4 = DAT_00fc1914 - DAT_00fc1910;
        _DAT_00fc19f0 = FUN_0089289d();
        _DAT_00fc19f0 = _DAT_00fc19f0 % (uint)(iVar4 / 0x1c);
        local_c = 0xffffffff;
        if (iStack_28 != 0) {
          FUN_00440a80();
          FUN_0089120c(iStack_28);
        }
      }
    }
    (**(code **)(*(int *)param_1[4] + 0xac))((int *)param_1[4],0,0,7,0xff000000,0x3f800000,0);
    (**(code **)(*(int *)param_1[4] + 0x44))((int *)param_1[4],0,0,0,0);
    (**(code **)(*(int *)param_1[4] + 0xac))((int *)param_1[4],0,0,7,0xff000000,0x3f800000,0);
    (**(code **)(*param_1 + 0x38))(param_1);
    (**(code **)(*(int *)param_1[4] + 0x44))((int *)param_1[4],0,0,0,0);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0xb;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  FUN_00797bc0(DAT_00fb76e8);
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    local_c = 0xc;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
    local_c = 0xffffffff;
  }
  (**(code **)(DAT_00fdf680 + 4))();
  FUN_007a4430();
  if ((_DAT_00fb79ec & 1) == 0) {
    _DAT_00fb79ec = _DAT_00fb79ec | 1;
    DAT_00fb79f0 = CCheckPointMgr::vftable;
    DAT_00fb79f4 = 0;
    DAT_00fb79f8 = 0;
    DAT_00fb79fc = 0;
    DAT_00fb7a04 = 1;
    _atexit((_func_4879 *)&LAB_00bcd270);
  }
  (*(code *)DAT_00fb79f0[1])();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0xd;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  FUN_004e11f0(*DAT_00fab13c,DAT_00fab13c,uStack_2c);
  (**(code **)(*DAT_00fba7a4 + 0x24))();
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 0xe;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_c = 0xffffffff;
  }
  FUN_00560aa0(&DAT_00fb73c0);
  if ((DAT_00fd9244 & 1) == 0) {
    DAT_00fd9244 = DAT_00fd9244 | 1;
    local_c = 0xf;
    FUN_00554410();
    _atexit((_func_4879 *)&LAB_00bcdfc0);
    local_c = 0xffffffff;
  }
  if (DAT_00fd9250 != 0) {
    FUN_007cd580();
  }
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  FUN_0056e230();
  if ((_DAT_00fd8f0c & 1) == 0) {
    _DAT_00fd8f0c = _DAT_00fd8f0c | 1;
    FUN_00559120();
    _atexit((_func_4879 *)&DAT_00bcdf60);
  }
  FUN_005592b0();
  FUN_0048a010();
  FUN_0041dc80();
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_c = 0x10;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
    local_c = 0xffffffff;
  }
  FUN_005535e0();
  if ((DAT_00fd8ea8 & 1) == 0) {
    DAT_00fd8ea8 = DAT_00fd8ea8 | 1;
    local_c = 0x11;
    FUN_0055ac10();
    _atexit((_func_4879 *)&LAB_00bcdfe0);
    local_c = 0xffffffff;
  }
  FUN_007383e0("UI/Data/TalkBalloon.eif");
  if ((_DAT_00fd2b98 & 1) == 0) {
    _DAT_00fd2b98 = _DAT_00fd2b98 | 1;
    DAT_00fd2b9c = 0;
    DAT_00fd2ba0 = 0;
    DAT_00fd2ba4 = 0;
    DAT_00fd2ba8 = 0;
    _DAT_00fd2bac = 0;
    _DAT_00fd2bb0 = 0;
  }
  else if ((DAT_00fd2ba8 != 0) && (DAT_00fd2ba4 == 0)) {
    DAT_00fd2b9c = FUN_00734330("Contents_Class.dds","UI/ImageSets");
    DAT_00fd2ba0 = FUN_00734330("Contents_Class2.dds","UI/ImageSets");
    if ((DAT_00fd2b9c != 0) && (DAT_00fd2ba0 != 0)) {
      DAT_00fd2ba4 = 1;
    }
  }
  if ((DAT_00fc1bf4 & 1) == 0) {
    DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
    local_c = 0x12;
    FUN_0057ef90();
    _atexit((_func_4879 *)&LAB_00bcdfb0);
    local_c = 0xffffffff;
  }
  _DAT_00fc1c7c = param_1[0x2fd4];
  FUN_0057f670(_DAT_00fc1c7c);
  if ((DAT_00fb131c & 1) == 0) {
    DAT_00fb131c = DAT_00fb131c | 1;
    local_c = 0x13;
    FUN_00570ec0();
    _atexit((_func_4879 *)&LAB_00bccf50);
    local_c = 0xffffffff;
  }
  uVar3 = 0;
  do {
    if (*(int **)((int)&DAT_00fb1320 + uVar3) != (int *)0x0) {
      (**(code **)(**(int **)((int)&DAT_00fb1320 + uVar3) + 4))();
    }
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0xc);
  if (param_1[0x2ff4] != 0) {
    iVar4 = FUN_00891268(0x5eac);
    if (iVar4 != 0) {
      puVar6 = (undefined4 *)FUN_004add50();
      *puVar6 = Scene::CFirstScene::vftable;
      DAT_00d6a674 = 0x46495253;
    }
    if ((_DAT_00fd2cf4 & 1) == 0) {
      _DAT_00fd2cf4 = _DAT_00fd2cf4 | 1;
      DAT_00fd2cf8 = CSceneManager::vftable;
      DAT_00fd8ba4 = 0;
      FUN_004b7dc0();
      _atexit((_func_4879 *)&LAB_00bcdcf0);
    }
    FUN_004b7d50();
  }
  if ((_DAT_00fd9408 & 1) == 0) {
    _DAT_00fd9408 = _DAT_00fd9408 | 1;
    DAT_00fd940c = 0;
    _DAT_00fd9410 = 0;
    DAT_00fd9414 = (undefined4 *)0x0;
    _DAT_00fd9418 = 0;
  }
  DAT_00fd9414 = (undefined4 *)FUN_00891268(0x28);
  if (DAT_00fd9414 == (undefined4 *)0x0) {
    DAT_00fd9414 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(DAT_00fd9414 + 1) = 0;
    DAT_00fd9414[3] = 0;
    DAT_00fd9414[4] = 0;
    DAT_00fd9414[5] = 0;
    DAT_00fd9414[6] = 0;
    *DAT_00fd9414 = Graphics::CImageSprite::vftable;
  }
  FUN_007383e0("UI/Data/ThreadLoading_Ico.eif");
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  DAT_00fd2bb8 = 1;
  iVar4 = param_1[0x2ff7];
  if (*(int *)(iVar4 + 4) == 0) {
    *(undefined4 *)(iVar4 + 4) = 1;
    (**(code **)(**(int **)(iVar4 + 0x18) + 8))();
  }
  if (param_1[0x2ff8] != 0) {
    FUN_006dc890(param_1[0x2ff8]);
  }
  if (param_1[0x2ff4] == 0) {
    if ((DAT_00fc18fc & 1) == 0) {
      DAT_00fc18fc = DAT_00fc18fc | 1;
      local_c = 0x14;
      FUN_005548f0();
      _atexit((_func_4879 *)&LAB_00bcdcd0);
      local_c = 0xffffffff;
    }
    if (DAT_00fc1984 != 0) {
      FUN_005558c0();
    }
  }
  else {
    if ((_DAT_00fc18dc & 1) == 0) {
      _DAT_00fc18dc = _DAT_00fc18dc | 1;
      _DAT_00fc18f0 = 0;
      DAT_00fc18f4 = (undefined4 *)0x0;
      _DAT_00fc18f8 = 0x1ff0000;
      _atexit((_func_4879 *)&DAT_00bce270);
    }
    if (((HANDLE)*DAT_00fc18f4 != (HANDLE)0xffffffff) &&
       (DVar7 = WaitForSingleObject((HANDLE)*DAT_00fc18f4,0), DVar7 == 0x102)) {
      PostThreadMessageW(DAT_00fc18f4[1],0x12,0,100);
    }
    if (DAT_00fc18f4 != (undefined4 *)0x0) {
      FUN_004fb7d0();
      DAT_00fc18f4 = (undefined4 *)0x0;
    }
    FUN_0048ee10(param_1[2]);
  }
  param_1[0x2ff3] = 0;
  param_1[0x301d] = 1;
  ExceptionList = local_14;
  return 0;
}

