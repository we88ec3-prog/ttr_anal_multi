
char * FUN_0070a230(undefined4 param_1,char *param_2)

{
  char cVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *_Filename;
  FILE *_File;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar2 = FUN_006f6740(&DAT_00c41190,&DAT_00c420d4);
  *(undefined4 *)(in_EAX + 0x58) = *(undefined4 *)(**(int **)(*(int *)(in_EAX + 0x14) + 4) + 0xc);
  *(undefined4 *)(in_EAX + 0x60) = 5;
  do {
    cVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_006fec70();
  FUN_006fb850();
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  iVar3 = *(int *)(in_EAX + 8);
  if (*(int *)(iVar3 + -8) == 4) {
LAB_0070a2dc:
    if (*(int *)(iVar3 + -0x10) != -0x10) goto LAB_0070a2f5;
  }
  else {
    iVar3 = FUN_006fb5d0();
    if (iVar3 != 0) {
      if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
        FUN_006fb3a0();
      }
      iVar3 = *(int *)(in_EAX + 8);
      goto LAB_0070a2dc;
    }
  }
  FUN_006f5f30();
LAB_0070a2f5:
  if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar5 = *(undefined4 **)(in_EAX + 8);
  uVar4 = FUN_006fec70();
  *puVar5 = uVar4;
  puVar5[2] = 4;
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  iVar3 = FUN_0070a1a0();
  while( true ) {
    if (iVar3 == 0) {
      return (char *)0x0;
    }
    if (((*(int *)(*(int *)(in_EAX + 8) + -8) != 4) && (iVar3 = FUN_006fb5d0(), iVar3 != 0)) &&
       (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44))) {
      FUN_006fb3a0();
    }
    _Filename = (char *)FUN_006f6740(&DAT_00c42700,uVar2);
    puVar6 = *(undefined4 **)(in_EAX + 8);
    puVar5 = puVar6 + -4;
    if (puVar5 < puVar6) {
      puVar6 = puVar6 + -8;
      do {
        *puVar6 = *puVar5;
        puVar6[1] = puVar5[1];
        puVar6[2] = puVar6[6];
        puVar5 = puVar5 + 4;
        puVar6 = puVar6 + 4;
      } while (puVar5 < *(undefined4 **)(in_EAX + 8));
    }
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
    _File = _fopen(_Filename,"r");
    if (_File != (FILE *)0x0) break;
    FUN_006f5580();
    puVar6 = *(undefined4 **)(in_EAX + 8);
    puVar5 = puVar6 + -4;
    if (puVar5 < puVar6) {
      puVar6 = puVar6 + -8;
      do {
        *puVar6 = *puVar5;
        puVar6[1] = puVar5[1];
        puVar6[2] = puVar6[6];
        puVar5 = puVar5 + 4;
        puVar6 = puVar6 + 4;
      } while (puVar5 < *(undefined4 **)(in_EAX + 8));
    }
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
    if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    FUN_006fc080();
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
    iVar3 = FUN_0070a1a0();
  }
  _fclose(_File);
  return _Filename;
}

