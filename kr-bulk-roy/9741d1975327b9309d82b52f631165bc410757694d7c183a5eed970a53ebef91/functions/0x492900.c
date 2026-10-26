
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00492900(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 extraout_ECX;
  undefined4 uVar5;
  void *pvVar6;
  void *pvVar7;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00949610;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(param_1 + 0xbfcc) == 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0;
      FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_c = 0xffffffff;
    piVar2 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
    pvVar7 = (void *)0x3f800000;
    pvVar6 = (void *)0x0;
    (**(code **)(*piVar2 + 0xac))(piVar2,0,0,7,DAT_00fb79a4,0x3f800000,0);
  }
  else {
    pvVar7 = (void *)0x3f800000;
    pvVar6 = (void *)0x0;
    (**(code **)(**(int **)(param_1 + 0x10) + 0xac))(*(int **)(param_1 + 0x10),0,0,3,0,0x3f800000,0)
    ;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 0xa4))(*(int **)(param_1 + 0x10));
  if (-1 < iVar3) {
    if (*(int *)(param_1 + 0xbfcc) != 0) {
      iVar3 = (**(code **)(**(int **)(param_1 + 0xbf50) + 0x20))(*(int **)(param_1 + 0xbf50),0x10);
      if (-1 < iVar3) {
        FUN_00489bf0();
        FUN_00555350();
        (**(code **)(**(int **)(param_1 + 0xbf50) + 0x2c))(*(int **)(param_1 + 0xbf50));
      }
      iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 0xa8))(*(int **)(param_1 + 0x10));
      ExceptionList = pvVar6;
      return iVar3;
    }
    if ((DAT_00fdf6f4 & 1) == 0) {
      DAT_00fdf6f4 = DAT_00fdf6f4 | 1;
      FUN_0049b490();
    }
    if ((_DAT_00fe48d8 & 1) == 0) {
      _DAT_00fe48d8 = _DAT_00fe48d8 | 1;
      FUN_0049b310();
    }
    FUN_0049b410();
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    iVar3 = *(int *)(param_1 + 0xbfdc);
    if (((uint)(DAT_00fb90f9 != '\0') != *(uint *)(iVar3 + 0x1c)) &&
       (*(uint *)(iVar3 + 0x1c) = (uint)(DAT_00fb90f9 != '\0'), *(int *)(iVar3 + 0x20) == 0)) {
      FUN_006d6120();
    }
    (**(code **)(**(int **)(*(int *)(param_1 + 0xbfdc) + 0x18) + 0x18))();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
    FUN_0040f060();
    FUN_004e0540();
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      FUN_00560170();
      _atexit((_func_4879 *)&LAB_00bcd110);
    }
    FUN_005616f0();
    iVar3 = FUN_00489cb0();
    if (*(int *)(iVar3 + 0x5eac) != 0) {
      (**(code **)(**(int **)(iVar3 + 0x5eac) + 0x20))();
    }
    if ((DAT_00fd93f0 & 1) == 0) {
      DAT_00fd93f0 = DAT_00fd93f0 | 1;
      FUN_007ab4e0();
      _atexit((_func_4879 *)&LAB_00bce6a0);
    }
    piVar2 = (int *)*DAT_00fd92a0;
    if (piVar2 != DAT_00fd92a0) {
      do {
        (**(code **)(*(int *)piVar2[2] + 8))();
        piVar2 = (int *)*piVar2;
      } while (piVar2 != DAT_00fd92a0);
    }
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
    }
    puVar1 = DAT_00fdf684;
    for (puVar4 = (undefined4 *)*DAT_00fdf684; puVar4 != puVar1; puVar4 = (undefined4 *)*puVar4) {
      if (*(int *)(puVar4[2] + 0x24) != 0) {
        FUN_007bdf40(*(int *)(puVar4[2] + 0x24));
      }
    }
    if ((DAT_00fc125c & 1) == 0) {
      DAT_00fc125c = DAT_00fc125c | 1;
      FUN_007b7260();
      _atexit((_func_4879 *)&LAB_00bce650);
    }
    iVar3 = 0;
    if (0 < DAT_00fc1688) {
      do {
        (**(code **)(*(int *)(&DAT_00fc1288)[iVar3] + 8))();
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_00fc1688);
    }
    if ((DAT_00fc1bf4 & 1) == 0) {
      DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
      FUN_0057ef90();
      _atexit((_func_4879 *)&LAB_00bcdfb0);
    }
    if ((DAT_00fc1c6c != 0) && (DAT_00fc1c4c != (int *)0x0)) {
      (**(code **)(*DAT_00fc1c4c + 0x10))();
    }
    if ((DAT_00fd9244 & 1) == 0) {
      DAT_00fd9244 = DAT_00fd9244 | 1;
      FUN_00554410();
      _atexit((_func_4879 *)&LAB_00bcdfc0);
    }
    FUN_00554850();
    if ((DAT_00fab100 & 1) == 0) {
      DAT_00fab100 = DAT_00fab100 | 1;
      FUN_0049d6a0();
      _atexit((_func_4879 *)&LAB_00bcce20);
    }
    if ((DAT_00fab104 & 8) != 0) {
      FUN_0049d9c0();
    }
    if ((DAT_00fe7270 & 1) == 0) {
      DAT_00fe7270 = DAT_00fe7270 | 1;
      DAT_00fe723c = 0xf;
      _DAT_00fe7238 = 0;
      DAT_00fe7228 = (undefined4 *)((uint)DAT_00fe7228 & 0xffffff00);
      FUN_00402a70(&DAT_00bf2375,0);
      _atexit((_func_4879 *)&LAB_00bce620);
    }
    if (DAT_00fdf70c == 0) {
      _DAT_00fe7238 = 0;
      puVar4 = DAT_00fe7228;
      if (DAT_00fe723c < 0x10) {
        puVar4 = &DAT_00fe7228;
      }
      *(undefined1 *)puVar4 = 0;
      FUN_00434740();
      FUN_0079ba30();
      DAT_00fdf70c = 0x1e;
    }
    else {
      DAT_00fdf70c = DAT_00fdf70c + -1;
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    FUN_00799f20();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
    FUN_007b40a0();
    if ((DAT_00fcde44 & 1) == 0) {
      DAT_00fcde44 = DAT_00fcde44 | 1;
      FUN_0055b8a0();
      _atexit(FUN_00bcdef0);
    }
    FUN_0055bce0();
    if ((DAT_00fd8ea8 & 1) == 0) {
      DAT_00fd8ea8 = DAT_00fd8ea8 | 1;
      FUN_0055ac10();
      _atexit((_func_4879 *)&LAB_00bcdfe0);
    }
    FUN_0055b0b0(&DAT_00fd8eb0);
    FUN_0048a400();
    FUN_006d8660();
    (**(code **)(**(int **)(*(int *)(param_1 + 0xbfdc) + 0x18) + 0x20))();
    iVar3 = (**(code **)(**(int **)(param_1 + 0xbf50) + 0x20))(*(int **)(param_1 + 0xbf50),0x10);
    if (-1 < iVar3) {
      FUN_00422f40();
      FUN_005646e0();
      uVar5 = 0;
      FUN_00422ed0(0);
      FUN_005539a0(uVar5);
      FUN_0048a8c0();
      FUN_0056ba10();
      (**(code **)(**(int **)(param_1 + 0xbf50) + 0x2c))(*(int **)(param_1 + 0xbf50));
    }
    iVar3 = FUN_00404ba0();
    if (*(char *)(iVar3 + 0x68c4) != '\0') {
      FUN_004054c0();
      FUN_0058a800();
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0xbf50) + 0x20))(*(int **)(param_1 + 0xbf50),0x10);
    if (-1 < iVar3) {
      uVar5 = FUN_00489e70();
      FUN_00558510(uVar5);
      iVar3 = FUN_00414720();
      if (*(int *)(iVar3 + 0xc) != 0) {
        (**(code **)(**(int **)(iVar3 + 0xc) + 0x1c))();
      }
      uVar5 = 1;
      FUN_00422ed0(1);
      FUN_005539a0(uVar5);
      (**(code **)(*DAT_00fba7a4 + 0x38))();
      iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      if (iVar3 != 0) {
        FUN_00489fe0();
        FUN_00559680();
        iVar3 = FUN_0048a010();
        if (*(int *)(iVar3 + 0x268) != 0) {
          FUN_0041e000();
        }
      }
      FUN_0048a120();
      FUN_00582040();
      FUN_0048a190();
      FUN_00554220();
      uVar5 = FUN_004054c0();
      FUN_0058b8c0(uVar5);
      FUN_0048a240();
      FUN_007372c0();
      FUN_0049b0a0();
      FUN_007382f0();
      FUN_00489b90();
      FUN_0049b660();
      iVar3 = FUN_00489b90();
      if (2 < *(int *)(iVar3 + 8)) {
        puVar4 = DAT_00fe7228;
        if (DAT_00fe723c < 0x10) {
          puVar4 = &DAT_00fe7228;
        }
        uVar5 = FUN_00489b90(extraout_ECX,puVar4);
        FUN_0049bbc0(uVar5);
        iVar3 = FUN_0049aee0();
        uVar5 = FUN_00489b90("AnimationResource Count : %d",*(undefined4 *)(iVar3 + 0xa4));
        FUN_0049bbc0(uVar5);
        iVar3 = FUN_0049aee0();
        uVar5 = FUN_00489b90("AnimationDeleteReady Count : %d",*(undefined4 *)(iVar3 + 0xb0));
        FUN_0049bbc0(uVar5);
      }
      FUN_0048a550();
      FUN_004a46e0();
      uVar5 = FUN_0040cf80();
      FUN_0049e290(uVar5);
      (**(code **)(**(int **)(param_1 + 0xbf50) + 0x2c))(*(int **)(param_1 + 0xbf50));
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 0xa8))(*(int **)(param_1 + 0x10));
  }
  if (((*(int *)(param_1 + 0xbfe0) != 0) && (*(int *)(param_1 + 0xbfcc) == 0)) &&
     (*(int *)(*(int *)(param_1 + 0xbfe0) + 0xb0) != 0)) {
    FUN_006dcd30();
  }
  ExceptionList = pvVar7;
  return iVar3;
}

