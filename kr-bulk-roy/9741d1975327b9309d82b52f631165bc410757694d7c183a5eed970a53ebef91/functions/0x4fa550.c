
void FUN_004fa550(undefined4 param_1,wchar_t *param_2)

{
  short sVar1;
  FILE *_File;
  undefined4 uVar2;
  wchar_t *pwVar3;
  short *psVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_684;
  FILE *local_680;
  undefined4 local_67c;
  undefined4 local_678;
  undefined4 local_674;
  undefined4 local_670;
  undefined4 local_66c;
  undefined4 local_660;
  undefined4 local_65c;
  undefined1 local_658 [28];
  undefined4 local_63c [39];
  undefined4 local_5a0;
  undefined4 local_59c;
  undefined4 local_598;
  undefined1 local_594 [188];
  undefined1 local_4d8 [184];
  wchar_t local_420;
  undefined1 local_41e [510];
  undefined4 local_220;
  undefined1 local_21c [512];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00913031;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_684;
  ExceptionList = &local_14;
  local_66c = param_1;
  local_680 = (FILE *)0x0;
  __wfopen_s(&local_680,param_2,L"r, ccs=UTF-16LE");
  _File = local_680;
  if (local_680 != (FILE *)0x0) {
    local_420 = L'\0';
    _memset(local_41e,0,0x1fe);
    pwVar3 = _fgetws(&local_420,0xff,_File);
    while (pwVar3 != (wchar_t *)0x0) {
      _eh_vector_constructor_iterator_
                (local_4d8,0x24,5,(_func_void_void_ptr *)&LAB_004fa2f0,FUN_004fa440);
      local_c = 0;
      local_67c = 0;
      local_678 = 0;
      local_684 = 0;
      FID_conflict__swscanf(&local_420,L"%d\t%d\t%d",&local_67c,&local_678,&local_684);
      _memset(&local_420,0,0x200);
      if (5 < local_684) {
                    /* WARNING: Subroutine does not return */
        FUN_006edc70(&DAT_00c0d734);
      }
      _eh_vector_constructor_iterator_
                (local_658,0x24,5,(_func_void_void_ptr *)&LAB_004fa2f0,FUN_004fa440);
      local_c._0_1_ = 1;
      iVar7 = 0;
      local_660 = local_67c;
      local_65c = local_678;
      if (0 < local_684) {
        puVar6 = local_63c;
        do {
          pwVar3 = _fgetws(&local_420,0xff,local_680);
          if (pwVar3 == (wchar_t *)0x0) break;
          local_220 = 0;
          _memset(local_21c,0,0x1fc);
          local_674 = 0;
          local_670 = 0;
          FID_conflict__swscanf(&local_420,L"%s\t%d\t%d",&local_220,0x100,&local_674,&local_670);
          _memset(&local_420,0,0x200);
          psVar4 = (short *)&local_220;
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
          FUN_00402160(&local_220,(int)psVar4 - ((int)&local_220 + 2) >> 1);
          *puVar6 = local_674;
          puVar6[1] = local_670;
          iVar7 = iVar7 + 1;
          puVar6 = puVar6 + 9;
        } while (iVar7 < local_684);
      }
      local_5a0 = CONCAT22((undefined2)local_67c,(undefined2)local_678);
      local_59c = local_660;
      local_598 = local_65c;
      _eh_vector_copy_constructor_iterator_(local_594,local_658,0x24,5,FUN_004fb700,FUN_004fa440);
      uVar2 = local_66c;
      local_c._0_1_ = 2;
      uVar5 = FUN_004fb600(&local_5a0);
      FUN_004fb320(uVar2,uVar5);
      local_c._0_1_ = 1;
      _eh_vector_destructor_iterator_(local_594,0x24,5,FUN_004fa440);
      local_c = (uint)local_c._1_3_ << 8;
      _eh_vector_destructor_iterator_(local_658,0x24,5,FUN_004fa440);
      local_c = 0xffffffff;
      _eh_vector_destructor_iterator_(local_4d8,0x24,5,FUN_004fa440);
      pwVar3 = _fgetws(&local_420,0xff,local_680);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_684);
  return;
}

