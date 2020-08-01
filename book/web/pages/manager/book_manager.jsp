<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>图书管理</title>

	<%--引入文件html/css/jQuery--%>
	<%@include file="/pages/common/header.jsp"%>

	<script type="text/javascript">
		/**
		 *  给删除的a标签添加一个点击事件，用于确实是否删除
		 */
		$(function () {
			$("a.deleteClass").click(function () {
				/**
				 * confirm用于提示是否删除
				 * 参数是它显示内容一个时确认，另一个是取消
				 * 返回true表示确认，返回false表示取消
				 */
				confirm("你确认要删除【" + $(this).parent().parent().find("td:first").text() +"】？");
			})
		});
	</script>

</head>
<body>
	
	<div id="header">
			<img class="logo_img" alt="" src="../../static/img/logo.gif" >
			<span class="wel_word">图书管理系统</span>

		<%@include file="/pages/common/manger_menu.jsp"%>

	</div>
	
	<div id="main">
		<table>

			<c:forEach items="${requestScope.page.items}" var="book">
				<tr>
					<td>${book.name}</td>
					<td>${book.price}</td>
					<td>${book.author}</td>
					<td>${book.sales}</td>
					<td>${book.stock}</td>
					<td><a href="manager/bookServlet?action=getBook&id=${book.id}&pageNo=${requestScope.page.pageNo}">修改</a></td>
					<td><a class="deleteClass" href="manager/bookServlet?action=delete&id=${book.id}&pageNo=${requestScope.page.pageNo}">删除</a></td>
				</tr>
			</c:forEach>
			
			<tr>
				<td></td>
				<td></td>
				<td></td>
				<td></td>
				<td></td>
				<td></td>
				<td><a href="pages/manager/book_edit.jsp?pageNo=${requestScope.page.pageTotal}">添加图书</a></td>
			</tr>	
		</table>

		<div id="page_nav">
			<%--当尾首页时不显示上一页--%>
			<c:if test="${requestScope.page.pageNo > 1}">
				<a href="manager/bookServlet?action=page&&pageNo=1">首页</a>
				<a href="manager/bookServlet?action=page&&pageNo=${requestScope.page.pageNo-1}">上一页</a>
			</c:if>

			<%--输出页码的开始--%>
			<c:choose>
				<%--情况一当总页码小于5的情况下--%>
				<c:when test="${requestScope.page.pageTotal <= 5}">

<%--					<c:set var="begin" value="1"/>
					<c:set var="end" value="${requestScope.page.pageTotal}"/>--%>

					<c:forEach begin="1" end="${requestScope.page.pageTotal}" var="i">
						<c:if test="${i == requestScope.page.pageNo}">
							【${i}】
						</c:if>
						<c:if test="${i != requestScope.page.pageNo}">
							<a href="manager/bookServlet?action=page&pageNo=${i}">${i}</a>
						</c:if>
					</c:forEach>
				</c:when>

				<%--情况二，当总页码数大于5的情况下--%>
				<c:when test="${requestScope.page.pageTotal > 5}">

					<c:choose>
						<%--小情况1：1，2，3，4，5--%>
						<c:when test="${requestScope.page.pageNo <= 3}">


<%--							<c:set var="begin" value="1"/>
							<c:set var="end" value="5"/>--%>

							<c:forEach begin="1" end="5" var="i">
								<c:if test="${i == requestScope.page.pageNo}">
									【${i}】
								</c:if>
								<c:if test="${i != requestScope.page.pageNo}">
									<a href="manager/bookServlet?action=page&pageNo=${i}">${i}</a>
								</c:if>
							</c:forEach>
						</c:when>

						<%--小情况2：6，7，8，9，10--%>
						<c:when test="${requestScope.page.pageNo > requestScope.page.pageTotal - 3}">


<%--							<c:set var="begin" value="${requestScope.page.pageTotal - 4}"/>
							<c:set var="end" value="${requestScope.page.pageTotal}"/>--%>

							<c:forEach begin="${requestScope.page.pageTotal - 4}" end="${requestScope.page.pageTotal}"  var="i">
								<c:if test="${i == requestScope.page.pageNo}">
									【${i}】
								</c:if>
								<c:if test="${i != requestScope.page.pageNo}">
									<a href="manager/bookServlet?action=page&pageNo=${i}">${i}</a>
								</c:if>
							</c:forEach>
						</c:when>

						<%--小情况3：--%>
						<c:otherwise>

<%--							<c:set var="begin" value="${requestScope.page.pageNo - -2}"/>
							<c:set var="end" value="${requestScope.page.pageNo + 2}"/>--%>

							<c:forEach begin="${requestScope.page.pageNo - -2}" end="${requestScope.page.pageNo + 2}"
									   var="i">
								<c:if test="${i == requestScope.page.pageNo}">
									【${i}】
								</c:if>
								<c:if test="${i != requestScope.page.pageNo}">
									<a href="manager/bookServlet?action=page&pageNo=${i}">${i}</a>
								</c:if>
							</c:forEach>
						</c:otherwise>
					</c:choose>
				</c:when>
			</c:choose>

<%--			&lt;%&ndash;	打印页码&ndash;%&gt;
			<c:forEach begin="${begin}" end="${end}" var="i">
				<c:if test="${i == requestScope.page.pageNo}">
					【${i}】
				</c:if>
				<c:if test="${i != requestScope.page.pageNo}">
					<a href="manager/bookServlet?action=page&pageNo=${i}">${i}</a>
				</c:if>
			</c:forEach>--%>

			<%--当为末尾页时不显示下一页--%>
			<c:if test="${requestScope.page.pageNo<requestScope.page.pageTotal}">
				<a href="manager/bookServlet?action=page&&pageNo=${requestScope.page.pageNo+1}">下一页</a>
				<a href="manager/bookServlet?action=page&&pageNo=${requestScope.page.pageTotal}">末页</a>
			</c:if>
			共${requestScope.page.pageTotal}页，${requestScope.page.pageTotalCount}条记录
			到第<input value="${param.pageNo}" name="pn" id="pn_input"/>页
			<input id="searchPathBtn" type="button" value="确定">

			<script type="text/javascript">
				$(function () {
					//跳转到指定页码
					$("#searchPathBtn").click(function () {
						var pageNo = $("#pn_input").val();
						//记录总页码数
						var pageTotal = ${requestScope.page.pageTotal};
						if (pageNo >= 1 && pageNo <= pageTotal) {
							/**
							 * js提供了一个location地址栏对象
							 * 他有一个属性href可以获取浏览器地址栏中地址
							 */
							location.href = "${pageScope.basePath}manager/bookServlet?action=page&&pageNo=" + pageNo;
						} else {
							alert("输入的值不合法！");
						}
					})
				})
			</script>

		</div>
	</div>

	<%--静态包含引入页脚--%>
	<%@include file="/pages/common/footer.jsp"%>

</body>
</html>