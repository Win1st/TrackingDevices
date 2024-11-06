import Vue from 'vue'
import VueRouter from 'vue-router'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'HomePage',
    component: () => import('../views/Home.vue')
  },
  {
    path: '/home',
    name: 'HomePage',
    component: () => import('../views/Home.vue')
  },
  {
    path: '/history',
    name: 'HistoryPage',
    component: () => import('../views/History.vue')
  },
  {
    path: '/notification',
    name: 'NotificationPage',
    component: () => import('../views/Notification.vue')
  },
  {
    path: '/profile',
    name: 'ProfilePage',
    component: () => import('../views/Profile.vue')
  },
  {
    path: '/user/login',
    name: 'Login',
    component: () => import('../views/user/Login.vue')
  },
  {
    path: '/user/signup',
    name: 'Signup',
    component: () => import('../views/user/Signup.vue')
  },
  {
    path: '/slave0',
    name: 'SlaveMessage1',
    component: () => import('../views/slaves/slave0.vue')
  },
  {
    path: '/slave1',
    name: 'SlaveMessage2',
    component: () => import('../views/slaves/slave1.vue')
  },
  {
    path: '/slave2',
    name: 'SlaveMessage3',
    component: () => import('../views/slaves/slave2.vue')
  },
  {
    path: '/slave3',
    name: 'SlaveMessage4',
    component: () => import('../views/slaves/slave3.vue')
  },
  
]

const router = new VueRouter({
  mode: 'history',
  routes
})

export default router