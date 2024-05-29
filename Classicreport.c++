**&---------------------------------------------------------------------*
*& Report Z_ABHI_CLASSICALREPORTS
*&---------------------------------------------------------------------*
*&
*&---------------------------------------------------------------------*
"two table combination report"
REPORT z_abhi_classicalreports.

DATA : lv_ono TYPE z_deano.

SELECT-OPTIONS : sl_ono FOR lv_ono.

TYPES: BEGIN OF lty_data ,
         ono      TYPE z_deano,
         order_dt TYPE z_deaodate,
         pay_mode TYPE z_deapm,
         tol_amt  TYPE z_deatc,
       END OF lty_data.

DATA : lt_data TYPE TABLE OF lty_data.
DATA : lwa_data TYPE lty_data.

TYPES: BEGIN OF lty_data1 ,
         ono    TYPE z_deano,
         oino   TYPE z_deiono,
         odes   TYPE z_deiodes,
         oicost TYPE z_deicost,
       END OF lty_data1.

DATA : lt_data1 TYPE TABLE OF lty_data1.
DATA : lwa_data1 TYPE lty_data1.

TYPES: BEGIN OF lty_data2 ,
         ono      TYPE z_deano,
         order_dt TYPE z_deaodate,
         pay_mode TYPE z_deapm,
         tol_amt  TYPE z_deatc,
         oino     TYPE z_deiono,
         odes     TYPE z_deiodes,
         oicost   TYPE z_deicost,
       END OF lty_data2.

DATA : lt_data2 TYPE TABLE OF lty_data2.
DATA : lwa_data2 TYPE lty_data2.

SELECT ono , order_dt ,pay_mode ,tol_amt
  FROM zao_ht
  INTO TABLE @lt_data
  WHERE ono IN @sl_ono.

IF lt_data IS NOT INITIAL.
  SELECT ono, oino, odes, oicost
    FROM zao_iht
    INTO TABLE @lt_data1
    FOR ALL ENTRIES IN @lt_data
    WHERE ono = @lt_data-ono.

ENDIF.

LOOP AT lt_data INTO lwa_data.
  LOOP AT lt_data1 INTO lwa_data1 WHERE ono = lwa_data-ono.
    lwa_data2-ono = lwa_data-ono.
    lwa_data2-order_dt = lwa_data-order_dt.
    lwa_data2-pay_mode = lwa_data-pay_mode.
    lwa_data2-tol_amt = lwa_data-tol_amt.
    lwa_data2-oino = lwa_data1-oino.
    lwa_data2-odes = lwa_data1-odes.
    lwa_data2-oicost = lwa_data1-oicost.
    APPEND lwa_data2 TO lt_data2.
    CLEAR lwa_data2.
  ENDLOOP.
ENDLOOP.

LOOP at lt_data2 into lwa_data2.
  WRITE :/ lwa_data2-ono , lwa_data2-ono, lwa_data2-pay_mode, lwa_data2-tol_amt ,lwa_data2-oino ,lwa_data2-odes , lwa_data2-oicost.
ENDLOOP.


'Take a condition that in which u added data in header and not in lines so u need to get the header details respected fields only in that case just follow below code'
'check lv_flag usage details'
*&---------------------------------------------------------------------*
*& Report Z_ABHI_CLASSICALREPORTS
*&---------------------------------------------------------------------*
*&
*&---------------------------------------------------------------------*
"two table combination report"
REPORT z_abhi_classicalreports.

DATA : lv_ono TYPE z_deano.

SELECT-OPTIONS : sl_ono FOR lv_ono.

TYPES: BEGIN OF lty_data ,
         ono      TYPE z_deano,
         order_dt TYPE z_deaodate,
         pay_mode TYPE z_deapm,
         tol_amt  TYPE z_deatc,
       END OF lty_data.

DATA : lt_data TYPE TABLE OF lty_data.
DATA : lwa_data TYPE lty_data.

TYPES: BEGIN OF lty_data1 ,
         ono    TYPE z_deano,
         oino   TYPE z_deiono,
         odes   TYPE z_deiodes,
         oicost TYPE z_deicost,
       END OF lty_data1.

DATA : lt_data1 TYPE TABLE OF lty_data1.
DATA : lwa_data1 TYPE lty_data1.

TYPES: BEGIN OF lty_data2 ,
         ono      TYPE z_deano,
         order_dt TYPE z_deaodate,
         pay_mode TYPE z_deapm,
         tol_amt  TYPE z_deatc,
         oino     TYPE z_deiono,
         odes     TYPE z_deiodes,
         oicost   TYPE z_deicost,
       END OF lty_data2.

DATA : lt_data2 TYPE TABLE OF lty_data2.
DATA : lwa_data2 TYPE lty_data2.
Data : lv_flag type boolean.

SELECT ono , order_dt ,pay_mode ,tol_amt
  FROM zao_ht
  INTO TABLE @lt_data
  WHERE ono IN @sl_ono.

IF lt_data IS NOT INITIAL.
  SELECT ono, oino, odes, oicost
    FROM zao_iht
    INTO TABLE @lt_data1
    FOR ALL ENTRIES IN @lt_data
    WHERE ono = @lt_data-ono.

ENDIF.

LOOP AT lt_data INTO lwa_data.
  LOOP AT lt_data1 INTO lwa_data1 WHERE ono = lwa_data-ono.
    lwa_data2-ono = lwa_data-ono.
    lwa_data2-order_dt = lwa_data-order_dt.
    lwa_data2-pay_mode = lwa_data-pay_mode.
    lwa_data2-tol_amt = lwa_data-tol_amt.
    lwa_data2-oino = lwa_data1-oino.
    lwa_data2-odes = lwa_data1-odes.
    lwa_data2-oicost = lwa_data1-oicost.
    APPEND lwa_data2 TO lt_data2.
    lv_flag = 'X'.
    CLEAR lwa_data2.
  ENDLOOP.
  if lv_flag = ' '.
    lwa_data2-ono = lwa_data-ono.
    lwa_data2-order_dt = lwa_data-order_dt.
    lwa_data2-pay_mode = lwa_data-pay_mode.
    lwa_data2-tol_amt = lwa_data-tol_amt.
    CLEAR lv_flag .
ENDLOOP.

LOOP at lt_data2 into lwa_data2.
  WRITE :/ lwa_data2-ono , lwa_data2-ono, lwa_data2-pay_mode, lwa_data2-tol_amt ,lwa_data2-oino ,lwa_data2-odes , lwa_data2-oicost.
ENDLOOP.




REPORT z_abhi_classicalreports.

DATA : lv_ono TYPE z_deano.

SELECT-OPTIONS : sl_ono FOR lv_ono.

TYPES: BEGIN OF lty_data ,
         ono      TYPE z_deano,
         order_dt TYPE z_deaodate,
         pay_mode TYPE z_deapm,
         tol_amt  TYPE z_deatc,
       END OF lty_data.

DATA : lt_data TYPE TABLE OF lty_data.
DATA : lwa_data TYPE lty_data.

TYPES: BEGIN OF lty_data1 ,
         ono    TYPE z_deano,
         oino   TYPE z_deiono,
         odes   TYPE z_deiodes,
         oicost TYPE z_deicost,
       END OF lty_data1.

DATA : lt_data1 TYPE TABLE OF lty_data1.
DATA : lwa_data1 TYPE lty_data1.

TYPES: BEGIN OF lty_data2 ,
         ono      TYPE z_deano,
         order_dt TYPE z_deaodate,
         pay_mode TYPE z_deapm,
         tol_amt  TYPE z_deatc,
         oino     TYPE z_deiono,
         odes     TYPE z_deiodes,
         oicost   TYPE z_deicost,
       END OF lty_data2.

DATA : lt_data2 TYPE TABLE OF lty_data2.
DATA : lwa_data2 TYPE lty_data2.
Data : lv_flag type boolean.

SELECT ono , order_dt ,pay_mode ,tol_amt
  FROM zao_ht
  INTO TABLE @lt_data
  WHERE ono IN @sl_ono.

IF lt_data IS NOT INITIAL.
  SELECT ono, oino, odes, oicost
    FROM zao_iht
    INTO TABLE @lt_data1
    FOR ALL ENTRIES IN @lt_data
    WHERE ono = @lt_data-ono.

ENDIF.

sort lt_data1 by ono.

LOOP AT lt_data INTO lwa_data.
Read table lt_data1 into lwa_data1 with key = ono BINARY SEARCH.
If sy-subrc = 0.
  lv_index = sy-tabix.
Endif.

  LOOP AT lt_data1 INTO lwa_data1 from lv_index.
  if lwa_data-ono ne lwa_data1-ono.
  exit.
  else.
    lwa_data2-ono = lwa_data-ono.
    lwa_data2-order_dt = lwa_data-order_dt.
    lwa_data2-pay_mode = lwa_data-pay_mode.
    lwa_data2-tol_amt = lwa_data-tol_amt.
    lwa_data2-oino = lwa_data1-oino.
    lwa_data2-odes = lwa_data1-odes.
    lwa_data2-oicost = lwa_data1-oicost.
    APPEND lwa_data2 TO lt_data2.
    lv_flag = 'X'.
    CLEAR lwa_data2.
    endif.
  ENDLOOP.
  if lv_flag = ' '.
    lwa_data2-ono = lwa_data-ono.
    lwa_data2-order_dt = lwa_data-order_dt.
    lwa_data2-pay_mode = lwa_data-pay_mode.
    lwa_data2-tol_amt = lwa_data-tol_amt.
    CLEAR lv_flag .
ENDLOOP.

LOOP at lt_data2 into lwa_data2.
  WRITE :/ lwa_data2-ono , lwa_data2-ono, lwa_data2-pay_mode, lwa_data2-tol_amt ,lwa_data2-oino ,lwa_data2-odes , lwa_data2-oicost.
ENDLOOP.
