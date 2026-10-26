
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0086c3d0(char *param_1)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  undefined1 local_1d4 [12];
  undefined4 uStack_1c8;
  uint *local_1c4;
  char *local_1c0;
  uint local_1a8 [4];
  undefined4 local_198;
  uint local_194;
  uint local_188 [4];
  undefined4 local_178;
  uint local_174;
  undefined1 *local_164;
  undefined4 local_160;
  uint local_15c [4];
  undefined4 local_14c;
  uint local_148;
  undefined4 local_140;
  uint local_13c [4];
  undefined4 local_12c;
  uint local_128;
  byte local_120 [264];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00913bce;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fe5df0 & 1) == 0) {
    DAT_00fe5df0 = DAT_00fe5df0 | 1;
    local_8 = 0;
    local_1c0 = "UNKNOWN";
    local_194 = 0xf;
    local_198 = 0;
    local_1a8[0] = local_1a8[0] & 0xffffff00;
    local_1c4 = (uint *)0x86c443;
    FUN_00402a70();
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_1c0 = (char *)0x0;
    local_1c4 = local_1a8;
    local_8 = CONCAT31(local_8._1_3_,2);
    local_140 = 0;
    uStack_1c8 = 0x86c474;
    FUN_00403040();
    if (0xf < local_194) {
      local_1c0 = (char *)0x86c488;
      FUN_0089120c();
    }
    local_194 = 0xf;
    local_198 = 0;
    local_1a8[0] = local_1a8[0] & 0xffffff00;
    local_8._0_1_ = 3;
    local_1c0 = (char *)0x0;
    local_1c4 = local_13c;
    _DAT_00fe5b30 = local_140;
    _DAT_00fe5b48 = 0xf;
    _DAT_00fe5b44 = 0;
    DAT_00fe5b34 = 0;
    uStack_1c8 = 0x86c4d3;
    FUN_00403040();
    local_8._0_1_ = 5;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86c4eb;
      FUN_0089120c();
    }
    local_1c0 = "LOOPBYTYPE";
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = local_188[0] & 0xffffff00;
    local_1c4 = (uint *)0x86c524;
    FUN_00402a70();
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    local_1c0 = (char *)0x0;
    local_1c4 = local_188;
    local_8 = CONCAT31(local_8._1_3_,7);
    local_160 = 1;
    uStack_1c8 = 0x86c559;
    FUN_00403040();
    if (0xf < local_174) {
      local_1c0 = (char *)0x86c56d;
      FUN_0089120c();
    }
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = local_188[0] & 0xffffff00;
    local_8._0_1_ = 8;
    local_1c0 = (char *)0x0;
    local_1c4 = local_15c;
    DAT_00fe5b50 = local_160;
    DAT_00fe5b68 = 0xf;
    _DAT_00fe5b64 = 0;
    DAT_00fe5b54 = 0;
    uStack_1c8 = 0x86c5b8;
    FUN_00403040();
    local_8._0_1_ = 10;
    if (0xf < local_148) {
      local_1c0 = (char *)0x86c5d0;
      FUN_0089120c();
    }
    local_1c0 = "LOOPBYCOUNT";
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    local_194 = 0xf;
    local_198 = 0;
    local_1a8[0] = local_1a8[0] & 0xffffff00;
    local_1c4 = (uint *)0x86c609;
    FUN_00402a70();
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_1c0 = (char *)0x0;
    local_1c4 = local_1a8;
    local_8 = CONCAT31(local_8._1_3_,0xc);
    local_140 = 2;
    uStack_1c8 = 0x86c63e;
    FUN_00403040();
    if (0xf < local_194) {
      local_1c0 = (char *)0x86c652;
      FUN_0089120c();
    }
    local_194 = 0xf;
    local_198 = 0;
    local_1a8[0] = local_1a8[0] & 0xffffff00;
    local_8._0_1_ = 0xd;
    local_1c0 = (char *)0x0;
    local_1c4 = local_13c;
    _DAT_00fe5b70 = local_140;
    DAT_00fe5b88 = 0xf;
    _DAT_00fe5b84 = 0;
    DAT_00fe5b74._0_1_ = 0;
    uStack_1c8 = 0x86c69c;
    FUN_00403040();
    local_8._0_1_ = 0xf;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86c6b4;
      FUN_0089120c();
    }
    local_1c0 = "LOOPGETCOUNT";
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = local_188[0] & 0xffffff00;
    local_1c4 = (uint *)0x86c6ed;
    FUN_00402a70();
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    local_1c0 = (char *)0x0;
    local_1c4 = local_188;
    local_8 = CONCAT31(local_8._1_3_,0x11);
    local_160 = 3;
    uStack_1c8 = 0x86c722;
    FUN_00403040();
    if (0xf < local_174) {
      local_1c0 = (char *)0x86c736;
      FUN_0089120c();
    }
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = local_188[0] & 0xffffff00;
    local_8._0_1_ = 0x12;
    local_1c0 = (char *)0x0;
    local_1c4 = local_15c;
    _DAT_00fe5b90 = local_160;
    _DAT_00fe5ba8 = 0xf;
    _DAT_00fe5ba4 = 0;
    DAT_00fe5b94 = 0;
    uStack_1c8 = 0x86c781;
    FUN_00403040();
    local_8._0_1_ = 0x14;
    if (0xf < local_148) {
      local_1c0 = (char *)0x86c799;
      FUN_0089120c();
    }
    local_1c0 = "LOOPGETINDEX";
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    local_194 = 0xf;
    local_198 = 0;
    local_1a8[0] = local_1a8[0] & 0xffffff00;
    local_1c4 = (uint *)0x86c7d2;
    FUN_00402a70();
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_1c0 = (char *)0x0;
    local_1c4 = local_1a8;
    local_8 = CONCAT31(local_8._1_3_,0x16);
    local_140 = 4;
    uStack_1c8 = 0x86c807;
    FUN_00403040();
    if (0xf < local_194) {
      local_1c0 = (char *)0x86c81b;
      FUN_0089120c();
    }
    local_194 = 0xf;
    local_198 = 0;
    local_1a8[0] = local_1a8[0] & 0xffffff00;
    local_8._0_1_ = 0x17;
    local_1c0 = (char *)0x0;
    local_1c4 = local_13c;
    _DAT_00fe5bb0 = local_140;
    _DAT_00fe5bc8 = 0xf;
    _DAT_00fe5bc4 = 0;
    DAT_00fe5bb4 = 0;
    uStack_1c8 = 0x86c866;
    FUN_00403040();
    local_8._0_1_ = 0x19;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86c87e;
      FUN_0089120c();
    }
    local_1c0 = "LOOPUPDATE";
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = local_188[0] & 0xffffff00;
    local_1c4 = (uint *)0x86c8b7;
    FUN_00402a70();
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    local_1c0 = (char *)0x0;
    local_1c4 = local_188;
    local_8 = CONCAT31(local_8._1_3_,0x1b);
    local_160 = 5;
    uStack_1c8 = 0x86c8ec;
    FUN_00403040();
    if (0xf < local_174) {
      local_1c0 = (char *)0x86c900;
      FUN_0089120c();
    }
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = local_188[0] & 0xffffff00;
    local_8._0_1_ = 0x1c;
    local_1c0 = (char *)0x0;
    local_1c4 = local_15c;
    _DAT_00fe5bd0 = local_160;
    _DAT_00fe5be8 = 0xf;
    _DAT_00fe5be4 = 0;
    DAT_00fe5bd4 = 0;
    uStack_1c8 = 0x86c94a;
    FUN_00403040();
    local_8._0_1_ = 0x1e;
    if (0xf < local_148) {
      local_1c0 = (char *)0x86c962;
      FUN_0089120c();
    }
    local_1c0 = "LOOPEND";
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    local_194 = 0xf;
    local_198 = 0;
    local_1a8[0] = local_1a8[0] & 0xffffff00;
    local_1c4 = (uint *)0x86c99b;
    FUN_00402a70();
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_1c0 = (char *)0x0;
    local_1c4 = local_1a8;
    local_8 = CONCAT31(local_8._1_3_,0x20);
    local_140 = 6;
    uStack_1c8 = 0x86c9d0;
    FUN_00403040();
    if (0xf < local_194) {
      local_1c0 = (char *)0x86c9e4;
      FUN_0089120c();
    }
    local_194 = 0xf;
    local_198 = 0;
    local_1a8[0] = local_1a8[0] & 0xffffff00;
    local_8._0_1_ = 0x21;
    local_1c0 = (char *)0x0;
    local_1c4 = local_13c;
    _DAT_00fe5bf0 = local_140;
    _DAT_00fe5c08 = 0xf;
    _DAT_00fe5c04 = 0;
    DAT_00fe5bf4 = 0;
    uStack_1c8 = 0x86ca2f;
    FUN_00403040();
    local_8._0_1_ = 0x23;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86ca47;
      FUN_0089120c();
    }
    local_1c0 = "RENDERCOLORTARGET";
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = local_188[0] & 0xffffff00;
    local_1c4 = (uint *)0x86ca80;
    FUN_00402a70();
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    local_1c0 = (char *)0x0;
    local_1c4 = local_188;
    local_8 = CONCAT31(local_8._1_3_,0x25);
    local_160 = 7;
    uStack_1c8 = 0x86cab5;
    FUN_00403040();
    if (0xf < local_174) {
      local_1c0 = (char *)0x86cac9;
      FUN_0089120c();
    }
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = local_188[0] & 0xffffff00;
    local_8._0_1_ = 0x26;
    local_1c0 = (char *)0x0;
    local_1c4 = local_15c;
    _DAT_00fe5c10 = local_160;
    _DAT_00fe5c28 = 0xf;
    _DAT_00fe5c24 = 0;
    DAT_00fe5c14 = 0;
    uStack_1c8 = 0x86cb14;
    FUN_00403040();
    local_8._0_1_ = 0x28;
    if (0xf < local_148) {
      local_1c0 = (char *)0x86cb2c;
      FUN_0089120c();
    }
    local_1c0 = "RENDERDEPTHSTENCILTARGET";
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    local_194 = 0xf;
    local_198 = 0;
    local_1a8[0] = local_1a8[0] & 0xffffff00;
    local_1c4 = (uint *)0x86cb65;
    FUN_00402a70();
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_1c0 = (char *)0x0;
    local_1c4 = local_1a8;
    local_8 = CONCAT31(local_8._1_3_,0x2a);
    local_140 = 8;
    uStack_1c8 = 0x86cb9a;
    FUN_00403040();
    if (0xf < local_194) {
      local_1c0 = (char *)0x86cbae;
      FUN_0089120c();
    }
    local_194 = 0xf;
    local_198 = 0;
    local_1a8[0] = local_1a8[0] & 0xffffff00;
    local_8._0_1_ = 0x2b;
    local_1c0 = (char *)0x0;
    local_1c4 = local_13c;
    _DAT_00fe5c30 = local_140;
    _DAT_00fe5c48 = 0xf;
    _DAT_00fe5c44 = 0;
    DAT_00fe5c34 = 0;
    uStack_1c8 = 0x86cbf8;
    FUN_00403040();
    local_8._0_1_ = 0x2d;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86cc10;
      FUN_0089120c();
    }
    local_1c0 = "TECHNIQUE";
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = local_188[0] & 0xffffff00;
    local_1c4 = (uint *)0x86cc49;
    FUN_00402a70();
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    local_1c0 = (char *)0x0;
    local_1c4 = local_188;
    local_8 = CONCAT31(local_8._1_3_,0x2f);
    local_160 = 9;
    uStack_1c8 = 0x86cc7e;
    FUN_00403040();
    if (0xf < local_174) {
      local_1c0 = (char *)0x86cc92;
      FUN_0089120c();
    }
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = local_188[0] & 0xffffff00;
    local_8._0_1_ = 0x30;
    local_1c0 = (char *)0x0;
    local_1c4 = local_15c;
    _DAT_00fe5c50 = local_160;
    _DAT_00fe5c68 = 0xf;
    _DAT_00fe5c64 = 0;
    DAT_00fe5c54 = 0;
    uStack_1c8 = 0x86ccdd;
    FUN_00403040();
    local_8._0_1_ = 0x32;
    if (0xf < local_148) {
      local_1c0 = (char *)0x86ccf5;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_1c0 = (char *)0xf;
    local_1c4 = (uint *)0x0;
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    local_1d4[0] = 0;
    FUN_00402a70(&DAT_00c54c1c,4);
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x33;
    _DAT_00fe5c70 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5c88 = 0xf;
    _DAT_00fe5c84 = 0;
    DAT_00fe5c74 = 0;
    uStack_1c8 = 0x86cd68;
    FUN_00403040();
    local_8._0_1_ = 0x35;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86cd81;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_1c0 = (char *)0xf;
    local_1c4 = (uint *)0x0;
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    local_1d4[0] = 0;
    FUN_00402a70("MULTIPASS",9);
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x36;
    _DAT_00fe5c90 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5ca8 = 0xf;
    _DAT_00fe5ca4 = 0;
    DAT_00fe5c94 = 0;
    uStack_1c8 = 0x86cdf4;
    FUN_00403040();
    local_8._0_1_ = 0x38;
    if (0xf < local_148) {
      local_1c0 = (char *)0x86ce0d;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    FUN_00402b70(&DAT_00c54c08);
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x39;
    _DAT_00fe5cb0 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5cc8 = 0xf;
    _DAT_00fe5cc4 = 0;
    DAT_00fe5cb4 = 0;
    uStack_1c8 = 0x86ce76;
    FUN_00403040();
    local_8._0_1_ = 0x3b;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86ce8f;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    FUN_00402b70("SCRIPTSIGNATURE");
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x3c;
    _DAT_00fe5cd0 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5ce8 = 0xf;
    _DAT_00fe5ce4 = 0;
    DAT_00fe5cd4 = 0;
    uStack_1c8 = 0x86cef8;
    FUN_00403040();
    local_8._0_1_ = 0x3e;
    if (0xf < local_148) {
      local_1c0 = (char *)0x86cf11;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    FUN_00402b70("SCRIPTEXTERNAL");
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x3f;
    _DAT_00fe5cf0 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5d08 = 0xf;
    _DAT_00fe5d04 = 0;
    DAT_00fe5cf4 = 0;
    uStack_1c8 = 0x86cf7a;
    FUN_00403040();
    local_8._0_1_ = 0x41;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86cf93;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    FUN_00402b70("DESIGNATEDTECHNIQUE");
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x42;
    _DAT_00fe5d10 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5d28 = 0xf;
    _DAT_00fe5d24 = 0;
    DAT_00fe5d14 = 0;
    uStack_1c8 = 0x86cff9;
    FUN_00403040();
    local_8._0_1_ = 0x44;
    if (0xf < local_148) {
      local_1c0 = (char *)0x86d012;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    FUN_00402b70("CLEAR");
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x45;
    _DAT_00fe5d30 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5d48 = 0xf;
    _DAT_00fe5d44 = 0;
    DAT_00fe5d34 = 0;
    uStack_1c8 = 0x86d07b;
    FUN_00403040();
    local_8._0_1_ = 0x47;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86d094;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    FUN_00402b70("CLEARSETCOLOR");
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x48;
    _DAT_00fe5d50 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5d68 = 0xf;
    _DAT_00fe5d64 = 0;
    DAT_00fe5d54 = 0;
    uStack_1c8 = 0x86d0fd;
    FUN_00403040();
    local_8._0_1_ = 0x4a;
    if (0xf < local_148) {
      local_1c0 = (char *)0x86d116;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    FUN_00402b70("CLEARSETDEPTH");
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x4b;
    _DAT_00fe5d70 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5d88 = 0xf;
    _DAT_00fe5d84 = 0;
    DAT_00fe5d74 = 0;
    uStack_1c8 = 0x86d17f;
    FUN_00403040();
    local_8._0_1_ = 0x4d;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86d198;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    FUN_00402b70("CLEARSETSTENCIL");
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x4e;
    _DAT_00fe5d90 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5da8 = 0xf;
    _DAT_00fe5da4 = 0;
    DAT_00fe5d94 = 0;
    uStack_1c8 = 0x86d201;
    FUN_00403040();
    local_8._0_1_ = 0x50;
    if (0xf < local_148) {
      local_1c0 = (char *)0x86d21a;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_148 = 0xf;
    local_14c = 0;
    local_15c[0] = local_15c[0] & 0xffffff00;
    FUN_00402b70("GEOMETRYLIST");
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8._0_1_ = 0x51;
    _DAT_00fe5db0 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5dc8 = 0xf;
    _DAT_00fe5dc4 = 0;
    DAT_00fe5db4 = 0;
    uStack_1c8 = 0x86d283;
    FUN_00403040();
    local_8._0_1_ = 0x53;
    if (0xf < local_128) {
      local_1c0 = (char *)0x86d29c;
      FUN_0089120c();
    }
    local_164 = local_1d4;
    local_128 = 0xf;
    local_12c = 0;
    local_13c[0] = local_13c[0] & 0xffffff00;
    FUN_00402b70(&DAT_00c54b84);
    puVar4 = (undefined4 *)FUN_0086c350();
    local_8 = CONCAT31(local_8._1_3_,0x54);
    _DAT_00fe5dd0 = *puVar4;
    local_1c0 = (char *)0x0;
    local_1c4 = puVar4 + 1;
    _DAT_00fe5de8 = 0xf;
    _DAT_00fe5de4 = 0;
    DAT_00fe5dd4 = 0;
    uStack_1c8 = 0x86d305;
    FUN_00403040();
    if (0xf < local_148) {
      local_1c0 = (char *)0x86d31a;
      FUN_0089120c();
    }
    local_1c0 = (char *)0x86d327;
    _atexit((_func_4879 *)&LAB_00bd1030);
  }
  iVar6 = -(int)param_1;
  do {
    cVar2 = *param_1;
    param_1[(int)(local_120 + iVar6)] = cVar2;
    param_1 = param_1 + 1;
  } while (cVar2 != '\0');
  local_1c0 = (char *)0x86d34b;
  __strupr((char *)local_120);
  local_164 = (undefined1 *)0x1;
  pbVar7 = &DAT_00fe5b54;
  do {
    pbVar8 = pbVar7;
    if (0xf < *(uint *)(pbVar7 + 0x14)) {
      pbVar8 = *(byte **)pbVar7;
    }
    pbVar5 = local_120;
    do {
      bVar3 = *pbVar5;
      bVar9 = bVar3 < *pbVar8;
      if (bVar3 != *pbVar8) {
LAB_0086d392:
        iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_0086d397;
      }
      if (bVar3 == 0) break;
      bVar3 = pbVar5[1];
      bVar9 = bVar3 < pbVar8[1];
      if (bVar3 != pbVar8[1]) goto LAB_0086d392;
      pbVar5 = pbVar5 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar3 != 0);
    iVar6 = 0;
LAB_0086d397:
    if (iVar6 == 0) {
      pbVar8 = local_120;
      do {
        bVar3 = *pbVar8;
        pbVar8 = pbVar8 + 1;
      } while (bVar3 != 0);
      pbVar5 = pbVar7;
      if (0xf < *(uint *)(pbVar7 + 0x14)) {
        pbVar5 = *(byte **)pbVar7;
      }
      pbVar1 = pbVar5 + 1;
      do {
        bVar3 = *pbVar5;
        pbVar5 = pbVar5 + 1;
      } while (bVar3 != 0);
      if ((int)pbVar8 - (int)(local_120 + 1) == (int)pbVar5 - (int)pbVar1) break;
    }
    local_164 = (undefined1 *)((int)local_164 + 1);
    pbVar7 = pbVar7 + 0x20;
  } while (local_164 < 0x15);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

