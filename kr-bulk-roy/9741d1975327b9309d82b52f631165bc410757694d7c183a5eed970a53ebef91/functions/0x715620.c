
void FUN_00715620(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  char *in_EDX;
  char ****ppppcVar6;
  char *_Src;
  undefined4 local_654;
  undefined **local_650;
  undefined **local_64c;
  undefined **local_648;
  int *local_644;
  undefined1 local_640;
  undefined1 local_440;
  char ***local_434 [4];
  undefined4 local_424;
  uint local_420;
  char local_418;
  undefined1 local_417 [1023];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cdd6;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar3 = in_EDX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  _Src = (char *)(in_ECX + 0x158);
  FUN_00402a70(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  if (0xf < *(uint *)(in_ECX + 0x16c)) {
    _Src = *(char **)_Src;
  }
  _strcpy_s((char *)(in_ECX + 0xc),0x100,_Src);
  local_650 = BinFile::vftable;
  local_64c = BinFile::vftable;
  local_648 = BinFile::vftable;
  local_644 = (int *)0x0;
  local_440 = 0;
  local_640 = 0;
  local_8 = 0;
  local_420 = 0xf;
  local_424 = 0;
  local_434[0] = (char ***)((uint)local_434[0] & 0xffffff00);
  pcVar3 = in_EDX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00401fc0(&DAT_00c05630,4);
  uVar2 = 0;
  ppppcVar6 = (char ****)local_434[0];
  if (local_420 < 0x10) {
    ppppcVar6 = local_434;
  }
  local_418 = '\0';
  _memset(local_417,0,0x3ff);
  _strcat_s(&local_418,0x400,(char *)ppppcVar6);
  _strcpy_s((char *)&local_654,4,"rb");
  local_440 = 0;
  local_644 = (int *)FUN_00714770(&local_418,&local_654);
  if (local_644 == (int *)0x0) {
LAB_0071587e:
    local_644 = (int *)0x0;
    ppppcVar6 = (char ****)local_434[0];
    if (local_420 < 0x10) {
      ppppcVar6 = local_434;
    }
    local_418 = '\0';
    _memset(local_417,0,0x3ff);
    _strcat_s(&local_418,0x400,(char *)ppppcVar6);
    _strcpy_s((char *)&local_654,4,"rb");
    local_440 = uVar2;
    local_644 = (int *)FUN_00714770(&local_418,&local_654);
    if (local_644 == (int *)0x0) {
      local_644 = (int *)0x0;
      if (0xf < local_420) {
        FUN_0089120c(local_434[0]);
      }
      goto LAB_00715adc;
    }
    iVar4 = (**(code **)(*local_644 + 0x34))(4,0);
    if ((iVar4 < 0) && (local_644 != (int *)0x0)) {
      (**(code **)(*local_644 + 0x1c))();
    }
    (*(code *)*local_64c)(&local_654,4);
    if (local_644 == (int *)0x0) {
      FID_conflict__wprintf("File is not opened!\n");
    }
    else {
      iVar4 = (**(code **)(*local_644 + 0x34))(local_654,0);
      if ((iVar4 < 0) && (local_644 != (int *)0x0)) {
        (**(code **)(*local_644 + 0x1c))();
      }
    }
    uVar5 = FUN_00718460();
    if ((uVar5 ^ CONCAT31(CONCAT21(CONCAT11(uVar2,uVar2),uVar2),uVar2)) == 0x53545049) {
      (*(code *)*local_64c)(&local_654,4);
      iVar4 = FUN_00715480();
      if (iVar4 == 0) {
        if (local_644 != (int *)0x0) {
          (**(code **)(*local_644 + 4))();
        }
        local_644 = (int *)0x0;
        FUN_00402c50();
      }
      else {
        if (local_644 != (int *)0x0) {
          (**(code **)(*local_644 + 4))();
        }
        local_644 = (int *)0x0;
        iVar4 = FUN_007188d0(uVar2,param_1);
        if (iVar4 == 0) {
          (**(code **)**(undefined4 **)(*(int *)(in_ECX + 0x138) + 0x24))(0);
          FUN_00715ba0(0);
          FUN_00402c50();
        }
        else {
          FUN_00402c50();
        }
      }
      goto LAB_00715adc;
    }
    if (local_644 != (int *)0x0) {
      (**(code **)(*local_644 + 4))();
    }
  }
  else {
    iVar4 = FUN_007181c0();
    if (iVar4 == 0) {
      if (local_644 != (int *)0x0) {
        (**(code **)(*local_644 + 4))();
      }
      local_644 = (int *)0x0;
      iVar4 = FUN_007188d0(0,param_1);
      if (iVar4 == 0) {
        (**(code **)**(undefined4 **)(*(int *)(in_ECX + 0x138) + 0x24))(0);
        if (0xf < local_420) {
          FUN_0089120c(local_434[0]);
        }
      }
      else if (0xf < local_420) {
        FUN_0089120c(local_434[0]);
      }
      goto LAB_00715adc;
    }
    iVar4 = FUN_00718460();
    if (local_644 != (int *)0x0) {
      (**(code **)(*local_644 + 4))();
    }
    if (iVar4 == 0x53545044) {
      uVar2 = 0xff;
      goto LAB_0071587e;
    }
  }
  local_644 = (int *)0x0;
  if (0xf < local_420) {
    FUN_0089120c(local_434[0]);
  }
LAB_00715adc:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

