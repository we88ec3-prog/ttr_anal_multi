
void FUN_00446b30(undefined4 param_1)

{
  byte *pbVar1;
  short sVar2;
  code *pcVar3;
  short *psVar4;
  int iVar5;
  int in_ECX;
  short asStack_b0 [6];
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  wchar_t *pwStack_9c;
  short *local_84;
  int local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 local_68;
  uint local_64;
  uint uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009418f0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_84;
  ExceptionList = &local_14;
  *(undefined4 *)(in_ECX + 0x11c) = param_1;
  local_7c = in_ECX;
  if ((DAT_00fb93b8 & 1) == 0) {
    DAT_00fb93b8 = DAT_00fb93b8 | 1;
    local_c = 0;
    FUN_00823720();
    pwStack_9c = L"쒃褄Ⓖ\x88";
    _atexit(FUN_00bcd5a0);
  }
  local_c._0_1_ = 0xff;
  local_c._1_3_ = 0xffffff;
  local_80 = *(int *)(in_ECX + 0x11c);
  pwStack_9c = L"䒋ဤԻ鏀û萏࣍";
  FUN_008438c0();
  if ((local_84 != DAT_00fb93c0) &&
     (local_84 = (short *)(*(int *)(local_84 + 8) + 8), local_84 != (short *)0x0)) {
    if ((DAT_00fb93b8 & 1) == 0) {
      DAT_00fb93b8 = DAT_00fb93b8 | 1;
      local_c = 1;
      FUN_00823720();
      pwStack_9c = L"쒃褄Ⓖ\x88";
      _atexit(FUN_00bcd5a0);
      local_c._0_1_ = 0xff;
      local_c._1_3_ = 0xffffff;
    }
    pwStack_9c = L"ࢻ";
    pwStack_9c = (wchar_t *)FUN_00823620();
    local_c = 2;
    if (7 < *(uint *)(pwStack_9c + 10)) {
      pwStack_9c = *(wchar_t **)pwStack_9c;
    }
    local_78 = (uint)local_78._2_2_ << 0x10;
    local_64 = 7;
    local_68 = 0;
    psVar4 = pwStack_9c;
    do {
      sVar2 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar2 != 0);
    uStack_a0 = 0x446c8a;
    FUN_00402160();
    iVar5 = local_7c;
    local_c = CONCAT31(local_c._1_3_,3);
    pwStack_9c = L"辋ø";
    FUN_00757800();
    (**(code **)(**(int **)(iVar5 + 0xf8) + 200))();
    if (7 < local_64) {
      pwStack_9c = L"쒃㌄㏶뿒\a";
      FUN_0089120c();
    }
    local_64 = 7;
    local_68 = 0;
    local_78 = local_78 & 0xffff0000;
    if (7 < uStack_40) {
      pwStack_9c = L"쒃㌄觉⑼襰⑴晬䲉尤蓇蠤";
      FUN_0089120c();
    }
    uStack_24 = 7;
    uStack_28 = 0;
    uStack_38 = (uint)uStack_38._2_2_ << 0x10;
    local_c._1_3_ = 0;
    if ((DAT_00fb93b8 & 1) == 0) {
      DAT_00fb93b8 = DAT_00fb93b8 | 1;
      local_c._0_1_ = 5;
      local_c._1_3_ = 0;
      FUN_00823720();
      pwStack_9c = L"쒃옄⒄\x88";
      _atexit(FUN_00bcd5a0);
    }
    local_c._0_1_ = 4;
    pwStack_9c = L"蓆蠤";
    psVar4 = (short *)FUN_008236a0();
    local_c._0_1_ = 6;
    pwStack_9c = psVar4;
    if (7 < *(uint *)(psVar4 + 10)) {
      psVar4 = *(short **)psVar4;
      pwStack_9c = psVar4;
    }
    do {
      sVar2 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar2 != 0);
    uStack_a0 = 0x446d8f;
    FUN_00402160();
    local_c._0_1_ = 4;
    if (7 < uStack_40) {
      pwStack_9c = L"쒃樄栅롘¿璍搤䛨ﯕ\xf6ff逅弄Ā⥵ඃ䎐ù영⒄\x88";
      FUN_0089120c();
    }
    pwStack_9c = L"\n   \n";
    uStack_a0 = 0x446dba;
    FUN_00404300();
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 7;
      FUN_004e1590();
      pwStack_9c = L"쒃옄⒄\x88";
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c._0_1_ = 4;
    }
    iVar5 = FUN_004d43d0();
    psVar4 = local_84;
    pbVar1 = (byte *)(local_84 + 2);
    local_84 = (short *)0x28d;
    if (iVar5 < (int)(uint)*pbVar1) {
      iVar5 = FUN_00585620();
      pwStack_9c = 
      L"皋謄⑄㬔瓆㤌⑘䢍爐謊\xeb09찆ﲹ뻑言ч璍䀤볨﷿僿粺뾸贀⑴옠⒄\x8c";
      FUN_005740f0();
      if (local_80 == *(int *)(iVar5 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      FUN_00426ec0();
      local_c._0_1_ = 10;
      pwStack_9c = L"쒃樄櫿倀䲍栤蓆鐤";
      uStack_a0 = FUN_00447f50();
      pwStack_9c = (wchar_t *)0x0;
      local_c = CONCAT31(local_c._1_3_,0xb);
      uStack_a4 = 0x446f34;
      FUN_004041f0();
      if (7 < local_64) {
        pwStack_9c = L"쒃㌄움⒄\x88";
        FUN_0089120c();
      }
    }
    else {
      iVar5 = FUN_00585620();
      pwStack_9c = 
      L"皋謄⑄㬔瓆㤌⑘䢍爐謊\xeb09찆ﲹ뻑言ч璍䀤燨\xfe00僿撺뾸贀⑴蠠⒜\x8c";
      FUN_005740f0();
      if (local_80 == *(int *)(iVar5 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      FUN_00426ec0();
      local_c._0_1_ = 8;
      pwStack_9c = L"쒃樄櫿倀䲍栤蓆鐤";
      uStack_a0 = FUN_00447f50();
      pwStack_9c = (wchar_t *)0x0;
      local_c = CONCAT31(local_c._1_3_,9);
      uStack_a4 = 0x446e7e;
      FUN_004041f0();
      if (7 < local_64) {
        pwStack_9c = L"쒃㌄웒⒄\x88";
        FUN_0089120c();
      }
    }
    local_c._0_1_ = 4;
    local_78 = local_78 & 0xffff0000;
    local_68 = 0;
    local_64 = 7;
    if (7 < uStack_40) {
      local_c._0_1_ = 4;
      local_64 = 7;
      local_68 = 0;
      pwStack_9c = L"쒃\xf604逅弄Ā⥵ඃ䎐ù영⒄\x88";
      FUN_0089120c();
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 0xc;
      FUN_004e1590();
      pwStack_9c = L"쒃옄⒄\x88";
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c._0_1_ = 4;
    }
    iVar5 = FUN_004d43d0();
    local_84 = (short *)0x290;
    if (iVar5 < (int)(uint)*(byte *)(psVar4 + 2)) {
      iVar5 = FUN_00585620();
      pwStack_9c = 
      L"皋謄⑄㬔瓆㤌⑘䢍爐謊\xeb09찆ﲹ뻑言Շ璍䀤è﷾僿粺뾸贀⑴옠⒄\x8c";
      FUN_005740f0();
      if (local_80 == *(int *)(iVar5 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      FUN_00426ec0();
      local_c._0_1_ = 0xf;
      pwStack_9c = L"쒃樄櫿倀䲍栤蓆鐤";
      uStack_a0 = FUN_00447f50();
      pwStack_9c = (wchar_t *)0x0;
      local_c = CONCAT31(local_c._1_3_,0x10);
      uStack_a4 = 0x4470f0;
      FUN_004041f0();
      if (7 < local_64) {
        pwStack_9c = L"쒃㌄움⒄\x88";
        FUN_0089120c();
      }
    }
    else {
      iVar5 = FUN_00585620();
      pwStack_9c = 
      L"皋謄⑄㬔瓆㤌⑘䢍爐謊\xeb09찆ﲹ뻑言Շ璍䀤뛨﷾僿撺뾸贀⑴옠⒄\x8c";
      FUN_005740f0();
      if (local_80 == *(int *)(iVar5 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      FUN_00426ec0();
      local_c._0_1_ = 0xd;
      pwStack_9c = L"쒃樄櫿倀䲍栤蓆鐤";
      uStack_a0 = FUN_00447f50();
      pwStack_9c = (wchar_t *)0x0;
      local_c = CONCAT31(local_c._1_3_,0xe);
      uStack_a4 = 0x44703a;
      FUN_004041f0();
      if (7 < local_64) {
        pwStack_9c = L"쒃㌄웒⒄\x88";
        FUN_0089120c();
      }
    }
    local_c._0_1_ = 4;
    local_78 = local_78 & 0xffff0000;
    local_68 = 0;
    local_64 = 7;
    if (7 < uStack_40) {
      local_c._0_1_ = 4;
      local_64 = 7;
      local_68 = 0;
      pwStack_9c = L"쒃\xf604Ⰵ者Ā⥵ඃ눬ú영⒄\x88";
      FUN_0089120c();
    }
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c._0_1_ = 0x11;
      FUN_004dec90();
      pwStack_9c = L"쒃옄⒄\x88";
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c._0_1_ = 4;
    }
    local_84 = (short *)0x28e;
    if (*(short *)(DAT_00fab130 + 0x5eb4) < *psVar4) {
      iVar5 = FUN_00585620();
      pwStack_9c = 
      L"皋謄⑄㬔瓆㤌⑘䢍爐謊\xeb09찆ﲹ뻑昀ދ璍䀤㛨ﺾ僿粺뾸贀⑴옠⒄\x8c";
      FUN_005740f0();
      if (local_80 == *(int *)(iVar5 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      FUN_004330b0();
      local_c._0_1_ = 0x14;
      pwStack_9c = L"쒃樄櫿倀䲍栤蓆鐤";
      uStack_a0 = FUN_00447f50();
      pwStack_9c = (wchar_t *)0x0;
      local_c = CONCAT31(local_c._1_3_,0x15);
      uStack_a4 = 0x4472aa;
      FUN_004041f0();
      if (7 < local_64) {
        pwStack_9c = L"쒃㌄웉⒄\x88";
        FUN_0089120c();
      }
    }
    else {
      iVar5 = FUN_00585620();
      pwStack_9c = 
      L"皋謄⑄㬔瓆㤌⑘䢍爐謊\xeb09찆ﲹ뻑昀ދ璍䀤\xece8ﺾ僿撺뾸贀⑴옠⒄\x8c";
      FUN_005740f0();
      if (local_80 == *(int *)(iVar5 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      FUN_004330b0();
      local_c._0_1_ = 0x12;
      pwStack_9c = L"쒃樄櫿倀䲍栤蓆鐤";
      uStack_a0 = FUN_00447f50();
      pwStack_9c = (wchar_t *)0x0;
      local_c = CONCAT31(local_c._1_3_,0x13);
      uStack_a4 = 0x4471f4;
      FUN_004041f0();
      if (7 < local_64) {
        pwStack_9c = L"쒃㌄움⒄\x88";
        FUN_0089120c();
      }
    }
    local_c._0_1_ = 4;
    local_78 = local_78 & 0xffff0000;
    local_68 = 0;
    local_64 = 7;
    if (7 < uStack_40) {
      local_c._0_1_ = 4;
      local_64 = 7;
      local_68 = 0;
      pwStack_9c = L"쒃\xf604\xe405﹚Ā⹵ඃ嫤þ栁嫄þ蓆谤";
      FUN_0089120c();
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0x16;
      pwStack_9c = L"遨볳\xe800꿿D쒃옄⒄\x88";
      FUN_00584c40();
      pwStack_9c = L"쒃옄⒄\x88";
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c._0_1_ = 4;
    }
    local_84 = (short *)0x28f;
    pwStack_9c = 
    L"䒋ᐤԻ嫈þ౴堹贤၈ੲঋ۫만퇼¾警ɇ璍䀤䓨ﺽ僿钺뾸贀⑴옠⒄\x8c";
    FUN_005740f0();
    if (local_80 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_004330b0();
    local_c._0_1_ = 0x17;
    pwStack_9c = L"쒃樄櫿倀䲍栤蓆鐤";
    uStack_a0 = FUN_00447f50();
    pwStack_9c = (wchar_t *)0x0;
    local_c = CONCAT31(local_c._1_3_,0x18);
    uStack_a4 = 0x44739c;
    FUN_004041f0();
    if (7 < local_64) {
      pwStack_9c = L"쒃㌄㏶뿒\a";
      FUN_0089120c();
    }
    local_c._0_1_ = 4;
    local_64 = 7;
    local_68 = 0;
    local_78 = local_78 & 0xffff0000;
    if (7 < uStack_40) {
      pwStack_9c = L"쒃茄ᳬ첋撉Ⱔｪ赖⒄\x80";
      FUN_0089120c();
    }
    local_84 = asStack_b0;
    pwStack_9c = (wchar_t *)0x7;
    uStack_a0 = 0;
    asStack_b0[0] = 0;
    FUN_004026e0(&uStack_38,0,0xffffffff);
    FUN_004467e0();
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c._0_1_ = 0x19;
      FUN_005c3de0();
      pwStack_9c = L"쒃옄⒄\x88";
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c._0_1_ = 4;
    }
    if (DAT_00f943e0 != 0) {
      local_84 = *(short **)(local_7c + 0x11c);
      pwStack_9c = L"䒋ᐤ䘻琌謅၀˫쀳辋ô";
      FUN_0082ef00();
    }
    FUN_00745060();
    (**(code **)(**(int **)(local_7c + 0xf4) + 200))();
    pwStack_9c = L"尹瀤൲䒋尤\xe850鵢D쒃謄⒌\x80";
    FUN_00446890();
    if (7 < uStack_24) {
      pwStack_9c = L"쒃謄⒌\x80";
      FUN_0089120c();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_84);
  return;
}

